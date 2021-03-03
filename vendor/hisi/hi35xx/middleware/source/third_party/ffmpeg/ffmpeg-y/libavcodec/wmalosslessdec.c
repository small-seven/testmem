#include <inttypes.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "put_bits.h"
#include "lossless_audiodsp.h"
#include "wma.h"
#include "wma_common.h"
#define WMALL_MAX_CHANNELS      8                       ///< max number of handled channels
#define MAX_SUBFRAMES          32                       ///< max number of subframes per channel
#define MAX_BANDS              29                       ///< max number of scale factor bands
#define MAX_FRAMESIZE       32768                       ///< maximum compressed frame size
#define MAX_ORDER             256
#define WMALL_BLOCK_MIN_BITS    6                       ///< log2 of min block size
#define WMALL_BLOCK_MAX_BITS   14                       ///< log2 of max block size
#define WMALL_BLOCK_MAX_SIZE (1 << WMALL_BLOCK_MAX_BITS)    ///< maximum block size
#define WMALL_BLOCK_SIZES    (WMALL_BLOCK_MAX_BITS - WMALL_BLOCK_MIN_BITS + 1) ///< possible block sizes
#define WMALL_COEFF_PAD_SIZE   16                       ///< pad coef buffers with 0 for use with SIMD
typedef struct WmallChannelCtx {
    int16_t     prev_block_len;                         ///< length of the previous block
    uint8_t     transmit_coefs;
    uint8_t     num_subframes;
    uint16_t    subframe_len[MAX_SUBFRAMES];            ///< subframe length in samples
    uint16_t    subframe_offsets[MAX_SUBFRAMES];        ///< subframe positions in the current frame
    uint8_t     cur_subframe;                           ///< current subframe number
    uint16_t    decoded_samples;                        ///< number of already processed samples
    int         quant_step;                             ///< quantization step for the current subframe
    int         transient_counter;                      ///< number of transient samples from the beginning of the transient zone
} WmallChannelCtx;
typedef struct WmallDecodeCtx {
    /* generic decoder variables */
    AVCodecContext  *avctx;
    AVFrame         *frame;
    LLAudDSPContext dsp;                           ///< accelerated DSP functions
    uint8_t         *frame_data;                    ///< compressed frame data
    int             max_frame_size;                 ///< max bitstream size
    PutBitContext   pb;                             ///< context for filling the frame_data buffer

    /* frame size dependent frame information (set during initialization) */
    uint32_t        decode_flags;                   ///< used compression features
    int             len_prefix;                     ///< frame is prefixed with its length
    int             dynamic_range_compression;      ///< frame contains DRC data
    uint8_t         bits_per_sample;                ///< integer audio sample size for the unscaled IMDCT output (used to scale to [-1.0, 1.0])
    uint16_t        samples_per_frame;              ///< number of samples to output
    uint16_t        log2_frame_size;
    int8_t          num_channels;                   ///< number of channels in the stream (same as AVCodecContext.num_channels)
    int8_t          lfe_channel;                    ///< lfe channel index
    uint8_t         max_num_subframes;
    uint8_t         subframe_len_bits;              ///< number of bits used for the subframe length
    uint8_t         max_subframe_len_bit;           ///< flag indicating that the subframe is of maximum size when the first subframe length bit is 1
    uint16_t        min_samples_per_subframe;

    /* packet decode state */
    GetBitContext   pgb;                            ///< bitstream reader context for the packet
    int             next_packet_start;              ///< start offset of the next WMA packet in the demuxer packet
    uint8_t         packet_offset;                  ///< offset to the frame in the packet
    uint8_t         packet_sequence_number;         ///< current packet number
    int             num_saved_bits;                 ///< saved number of bits
    int             frame_offset;                   ///< frame offset in the bit reservoir
    int             subframe_offset;                ///< subframe offset in the bit reservoir
    uint8_t         packet_loss;                    ///< set in case of bitstream error
    uint8_t         packet_done;                    ///< set when a packet is fully decoded

    /* frame decode state */
    uint32_t        frame_num;                      ///< current frame number (not used for decoding)
    GetBitContext   gb;                             ///< bitstream reader context
    int             buf_bit_size;                   ///< buffer size in bits
    int16_t         *samples_16[WMALL_MAX_CHANNELS]; ///< current sample buffer pointer (16-bit)
    int32_t         *samples_32[WMALL_MAX_CHANNELS]; ///< current sample buffer pointer (24-bit)
    uint8_t         drc_gain;                       ///< gain for the DRC tool
    int8_t          skip_frame;                     ///< skip output step
    int8_t          parsed_all_subframes;           ///< all subframes decoded?

    /* subframe/block decode state */
    int16_t         subframe_len;                   ///< current subframe length
    int8_t          channels_for_cur_subframe;      ///< number of channels that contain the subframe
    int8_t          channel_indexes_for_cur_subframe[WMALL_MAX_CHANNELS];

    WmallChannelCtx channel[WMALL_MAX_CHANNELS];    ///< per channel data

    // WMA Lossless-specific

    uint8_t do_arith_coding;
    uint8_t do_ac_filter;
    uint8_t do_inter_ch_decorr;
    uint8_t do_mclms;
    uint8_t do_lpc;

    int8_t  acfilter_order;
    int8_t  acfilter_scaling;
    int16_t acfilter_coeffs[16];
    int     acfilter_prevvalues[WMALL_MAX_CHANNELS][16];

    int8_t  mclms_order;
    int8_t  mclms_scaling;
    int16_t mclms_coeffs[WMALL_MAX_CHANNELS * WMALL_MAX_CHANNELS * 32];
    int16_t mclms_coeffs_cur[WMALL_MAX_CHANNELS * WMALL_MAX_CHANNELS];
    int32_t mclms_prevvalues[WMALL_MAX_CHANNELS * 2 * 32];
    int32_t mclms_updates[WMALL_MAX_CHANNELS * 2 * 32];
    int     mclms_recent;

    int     movave_scaling;
    int     quant_stepsize;

    struct {
        int order;
        int scaling;
        int coefsend;
        int bitsend;
        DECLARE_ALIGNED(16, int16_t, coefs)[MAX_ORDER + WMALL_COEFF_PAD_SIZE/sizeof(int16_t)];
        DECLARE_ALIGNED(16, int32_t, lms_prevvalues)[MAX_ORDER * 2 + WMALL_COEFF_PAD_SIZE/sizeof(int16_t)];
        DECLARE_ALIGNED(16, int16_t, lms_updates)[MAX_ORDER * 2 + WMALL_COEFF_PAD_SIZE/sizeof(int16_t)];
        int recent;
    } cdlms[WMALL_MAX_CHANNELS][9];
#define WMASIGN(x) (((x) > 0) - ((x) < 0))
#define CD_LMS(bits, ROUND) \

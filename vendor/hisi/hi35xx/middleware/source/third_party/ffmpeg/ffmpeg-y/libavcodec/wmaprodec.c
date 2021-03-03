#include <inttypes.h>
#include "libavutil/ffmath.h"
#include "libavutil/float_dsp.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "put_bits.h"
#include "wmaprodata.h"
#include "sinewin.h"
#include "wma.h"
#include "wma_common.h"
#define WMAPRO_MAX_CHANNELS    8                             ///< max number of handled channels
#define MAX_SUBFRAMES  32                                    ///< max number of subframes per channel
#define MAX_BANDS      29                                    ///< max number of scale factor bands
#define MAX_FRAMESIZE  32768                                 ///< maximum compressed frame size
#define XMA_MAX_STREAMS         8
#define XMA_MAX_CHANNELS_STREAM 2
#define XMA_MAX_CHANNELS        (XMA_MAX_STREAMS * XMA_MAX_CHANNELS_STREAM)
#define WMAPRO_BLOCK_MIN_BITS  6                                           ///< log2 of min block size
#define WMAPRO_BLOCK_MAX_BITS 13                                           ///< log2 of max block size
#define WMAPRO_BLOCK_MIN_SIZE (1 << WMAPRO_BLOCK_MIN_BITS)                 ///< minimum block size
#define WMAPRO_BLOCK_MAX_SIZE (1 << WMAPRO_BLOCK_MAX_BITS)                 ///< maximum block size
#define WMAPRO_BLOCK_SIZES    (WMAPRO_BLOCK_MAX_BITS - WMAPRO_BLOCK_MIN_BITS + 1) ///< possible block sizes
#define VLCBITS            9
#define SCALEVLCBITS       8
#define VEC4MAXDEPTH    ((HUFF_VEC4_MAXBITS+VLCBITS-1)/VLCBITS)
#define VEC2MAXDEPTH    ((HUFF_VEC2_MAXBITS+VLCBITS-1)/VLCBITS)
#define VEC1MAXDEPTH    ((HUFF_VEC1_MAXBITS+VLCBITS-1)/VLCBITS)
#define SCALEMAXDEPTH   ((HUFF_SCALE_MAXBITS+SCALEVLCBITS-1)/SCALEVLCBITS)
#define SCALERLMAXDEPTH ((HUFF_SCALE_RL_MAXBITS+VLCBITS-1)/VLCBITS)
typedef struct WMAProChannelCtx {
    int16_t  prev_block_len;                          ///< length of the previous block
    uint8_t  transmit_coefs;
    uint8_t  num_subframes;
    uint16_t subframe_len[MAX_SUBFRAMES];             ///< subframe length in samples
    uint16_t subframe_offset[MAX_SUBFRAMES];          ///< subframe positions in the current frame
    uint8_t  cur_subframe;                            ///< current subframe number
    uint16_t decoded_samples;                         ///< number of already processed samples
    uint8_t  grouped;                                 ///< channel is part of a group
    int      quant_step;                              ///< quantization step for the current subframe
    int8_t   reuse_sf;                                ///< share scale factors between subframes
    int8_t   scale_factor_step;                       ///< scaling step for the current subframe
    int      max_scale_factor;                        ///< maximum scale factor for the current subframe
    int      saved_scale_factors[2][MAX_BANDS];       ///< resampled and (previously) transmitted scale factor values
    int8_t   scale_factor_idx;                        ///< index for the transmitted scale factor values (used for resampling)
    int*     scale_factors;                           ///< pointer to the scale factor values used for decoding
    uint8_t  table_idx;                               ///< index in sf_offsets for the scale factor reference block
    float*   coeffs;                                  ///< pointer to the subframe decode buffer
    uint16_t num_vec_coeffs;                          ///< number of vector coded coefficients
    DECLARE_ALIGNED(32, float, out)[WMAPRO_BLOCK_MAX_SIZE + WMAPRO_BLOCK_MAX_SIZE / 2]; ///< output buffer
} WMAProChannelCtx;
typedef struct WMAProChannelGrp {
    uint8_t num_channels;                                     ///< number of channels in the group
    int8_t  transform;                                        ///< transform on / off
    int8_t  transform_band[MAX_BANDS];                        ///< controls if the transform is enabled for a certain band
    float   decorrelation_matrix[WMAPRO_MAX_CHANNELS*WMAPRO_MAX_CHANNELS];
    float*  channel_data[WMAPRO_MAX_CHANNELS];                ///< transformation coefficients
} WMAProChannelGrp;
typedef struct WMAProDecodeCtx {
    /* generic decoder variables */
    AVCodecContext*  avctx;                         ///< codec context for av_log
    AVFloatDSPContext *fdsp;
    uint8_t          frame_data[MAX_FRAMESIZE +
                      AV_INPUT_BUFFER_PADDING_SIZE];///< compressed frame data
    PutBitContext    pb;                            ///< context for filling the frame_data buffer
    FFTContext       mdct_ctx[WMAPRO_BLOCK_SIZES];  ///< MDCT context per block size
    DECLARE_ALIGNED(32, float, tmp)[WMAPRO_BLOCK_MAX_SIZE]; ///< IMDCT output buffer
    const float*     windows[WMAPRO_BLOCK_SIZES];   ///< windows for the different block sizes

    /* frame size dependent frame information (set during initialization) */
    uint32_t         decode_flags;                  ///< used compression features
    uint8_t          len_prefix;                    ///< frame is prefixed with its length
    uint8_t          dynamic_range_compression;     ///< frame contains DRC data
    uint8_t          bits_per_sample;               ///< integer audio sample size for the unscaled IMDCT output (used to scale to [-1.0, 1.0])
    uint16_t         samples_per_frame;             ///< number of samples to output
    uint16_t         log2_frame_size;
    int8_t           lfe_channel;                   ///< lfe channel index
    uint8_t          max_num_subframes;
    uint8_t          subframe_len_bits;             ///< number of bits used for the subframe length
    uint8_t          max_subframe_len_bit;          ///< flag indicating that the subframe is of maximum size when the first subframe length bit is 1
    uint16_t         min_samples_per_subframe;
    int8_t           num_sfb[WMAPRO_BLOCK_SIZES];   ///< scale factor bands per block size
    int16_t          sfb_offsets[WMAPRO_BLOCK_SIZES][MAX_BANDS];                    ///< scale factor band offsets (multiples of 4)
    int8_t           sf_offsets[WMAPRO_BLOCK_SIZES][WMAPRO_BLOCK_SIZES][MAX_BANDS]; ///< scale factor resample matrix
    int16_t          subwoofer_cutoffs[WMAPRO_BLOCK_SIZES]; ///< subwoofer cutoff values

    /* packet decode state */
    GetBitContext    pgb;                           ///< bitstream reader context for the packet
    int              next_packet_start;             ///< start offset of the next wma packet in the demuxer packet
    uint8_t          packet_offset;                 ///< frame offset in the packet
    uint8_t          packet_sequence_number;        ///< current packet number
    int              num_saved_bits;                ///< saved number of bits
    int              frame_offset;                  ///< frame offset in the bit reservoir
    int              subframe_offset;               ///< subframe offset in the bit reservoir
    uint8_t          packet_loss;                   ///< set in case of bitstream error
    uint8_t          packet_done;                   ///< set when a packet is fully decoded
    uint8_t          eof_done;                      ///< set when EOF reached and extra subframe is written (XMA1/2)

    /* frame decode state */
    uint32_t         frame_num;                     ///< current frame number (not used for decoding)
    GetBitContext    gb;                            ///< bitstream reader context
    int              buf_bit_size;                  ///< buffer size in bits
    uint8_t          drc_gain;                      ///< gain for the DRC tool
    int8_t           skip_frame;                    ///< skip output step
    int8_t           parsed_all_subframes;          ///< all subframes decoded?
    uint8_t          skip_packets;                  ///< packets to skip to find next packet in a stream (XMA1/2)

    /* subframe/block decode state */
    int16_t          subframe_len;                  ///< current subframe length
    int8_t           nb_channels;                   ///< number of channels in stream (XMA1/2)
    int8_t           channels_for_cur_subframe;     ///< number of channels that contain the subframe
    int8_t           channel_indexes_for_cur_subframe[WMAPRO_MAX_CHANNELS];
    int8_t           num_bands;                     ///< number of scale factor bands
    int8_t           transmit_num_vec_coeffs;       ///< number of vector coded coefficients is part of the bitstream
    int16_t*         cur_sfb_offsets;               ///< sfb offsets for the current block
    uint8_t          table_idx;                     ///< index for the num_sfb, sfb_offsets, sf_offsets and subwoofer_cutoffs tables
    int8_t           esc_len;                       ///< length of escaped coefficients

    uint8_t          num_chgroups;                  ///< number of channel groups
    WMAProChannelGrp chgroup[WMAPRO_MAX_CHANNELS];  ///< channel group information

    WMAProChannelCtx channel[WMAPRO_MAX_CHANNELS];  ///< per channel data
} WMAProDecodeCtx;
typedef struct XMADecodeCtx {
    WMAProDecodeCtx xma[XMA_MAX_STREAMS];
    AVFrame *frames[XMA_MAX_STREAMS];
    int current_stream;
    int num_streams;
    float samples[XMA_MAX_CHANNELS][512 * 64];
    int offset[XMA_MAX_STREAMS];
    int start_channel[XMA_MAX_STREAMS];
} XMADecodeCtx;
#define PRINT(a, b)     av_log(s->avctx, AV_LOG_DEBUG, " %s = %d\n", a, b);
#define PRINT_HEX(a, b) av_log(s->avctx, AV_LOG_DEBUG, " %s = %"PRIx32"\n", a, b);

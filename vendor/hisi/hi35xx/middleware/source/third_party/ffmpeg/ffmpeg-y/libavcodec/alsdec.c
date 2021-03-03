#include <inttypes.h>
#include "avcodec.h"
#include "get_bits.h"
#include "unary.h"
#include "mpeg4audio.h"
#include "bgmc.h"
#include "bswapdsp.h"
#include "internal.h"
#include "mlz.h"
#include "libavutil/samplefmt.h"
#include "libavutil/crc.h"
#include "libavutil/softfloat_ieee754.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include <stdint.h>
typedef struct ALSSpecificConfig {
    uint32_t samples;         ///< number of samples, 0xFFFFFFFF if unknown
    int resolution;           ///< 000 = 8-bit; 001 = 16-bit; 010 = 24-bit; 011 = 32-bit
    int floating;             ///< 1 = IEEE 32-bit floating-point, 0 = integer
    int msb_first;            ///< 1 = original CRC calculated on big-endian system, 0 = little-endian
    int frame_length;         ///< frame length for each frame (last frame may differ)
    int ra_distance;          ///< distance between RA frames (in frames, 0...255)
    enum RA_Flag ra_flag;     ///< indicates where the size of ra units is stored
    int adapt_order;          ///< adaptive order: 1 = on, 0 = off
    int coef_table;           ///< table index of Rice code parameters
    int long_term_prediction; ///< long term prediction (LTP): 1 = on, 0 = off
    int max_order;            ///< maximum prediction order (0..1023)
    int block_switching;      ///< number of block switching levels
    int bgmc;                 ///< "Block Gilbert-Moore Code": 1 = on, 0 = off (Rice coding only)
    int sb_part;              ///< sub-block partition
    int joint_stereo;         ///< joint stereo: 1 = on, 0 = off
    int mc_coding;            ///< extended inter-channel coding (multi channel coding): 1 = on, 0 = off
    int chan_config;          ///< indicates that a chan_config_info field is present
    int chan_sort;            ///< channel rearrangement: 1 = on, 0 = off
    int rlslms;               ///< use "Recursive Least Square-Least Mean Square" predictor: 1 = on, 0 = off
    int chan_config_info;     ///< mapping of channels to loudspeaker locations. Unused until setting channel configuration is implemented.
    int *chan_pos;            ///< original channel positions
    int crc_enabled;          ///< enable Cyclic Redundancy Checksum
} ALSSpecificConfig;
typedef struct ALSChannelData {
    int stop_flag;
    int master_channel;
    int time_diff_flag;
    int time_diff_sign;
    int time_diff_index;
    int weighting[6];
} ALSChannelData;
typedef struct ALSDecContext {
    AVCodecContext *avctx;
    ALSSpecificConfig sconf;
    GetBitContext gb;
    BswapDSPContext bdsp;
    const AVCRC *crc_table;
    uint32_t crc_org;               ///< CRC value of the original input data
    uint32_t crc;                   ///< CRC value calculated from decoded data
    unsigned int cur_frame_length;  ///< length of the current frame to decode
    unsigned int frame_id;          ///< the frame ID / number of the current frame
    unsigned int js_switch;         ///< if true, joint-stereo decoding is enforced
    unsigned int cs_switch;         ///< if true, channel rearrangement is done
    unsigned int num_blocks;        ///< number of blocks used in the current frame
    unsigned int s_max;             ///< maximum Rice parameter allowed in entropy coding
    uint8_t *bgmc_lut;              ///< pointer at lookup tables used for BGMC
    int *bgmc_lut_status;           ///< pointer at lookup table status flags used for BGMC
    int ltp_lag_length;             ///< number of bits used for ltp lag value
    int *const_block;               ///< contains const_block flags for all channels
    unsigned int *shift_lsbs;       ///< contains shift_lsbs flags for all channels
    unsigned int *opt_order;        ///< contains opt_order flags for all channels
    int *store_prev_samples;        ///< contains store_prev_samples flags for all channels
    int *use_ltp;                   ///< contains use_ltp flags for all channels
    int *ltp_lag;                   ///< contains ltp lag values for all channels
    int **ltp_gain;                 ///< gain values for ltp 5-tap filter for a channel
    int *ltp_gain_buffer;           ///< contains all gain values for ltp 5-tap filter
    int32_t **quant_cof;            ///< quantized parcor coefficients for a channel
    int32_t *quant_cof_buffer;      ///< contains all quantized parcor coefficients
    int32_t **lpc_cof;              ///< coefficients of the direct form prediction filter for a channel
    int32_t *lpc_cof_buffer;        ///< contains all coefficients of the direct form prediction filter
    int32_t *lpc_cof_reversed_buffer; ///< temporary buffer to set up a reversed versio of lpc_cof_buffer
    ALSChannelData **chan_data;     ///< channel data for multi-channel correlation
    ALSChannelData *chan_data_buffer; ///< contains channel data for all channels
    int *reverted_channels;         ///< stores a flag for each reverted channel
    int32_t *prev_raw_samples;      ///< contains unshifted raw samples from the previous block
    int32_t **raw_samples;          ///< decoded raw samples for each channel
    int32_t *raw_buffer;            ///< contains all decoded raw samples including carryover samples
    uint8_t *crc_buffer;            ///< buffer of byte order corrected samples used for CRC check
    MLZ* mlz;                       ///< masked lz decompression structure
    SoftFloat_IEEE754 *acf;         ///< contains common multiplier for all channels
    int *last_acf_mantissa;         ///< contains the last acf mantissa data of common multiplier for all channels
    int *shift_value;               ///< value by which the binary point is to be shifted for all channels
    int *last_shift_value;          ///< contains last shift value for all channels
    int **raw_mantissa;             ///< decoded mantissa bits of the difference signal
    unsigned char *larray;          ///< buffer to store the output of masked lz decompression
    int *nbits;                     ///< contains the number of bits to read for masked lz decompression for all samples
} ALSDecContext;
typedef struct ALSBlockData {
    unsigned int block_length;      ///< number of samples within the block
    unsigned int ra_block;          ///< if true, this is a random access block
    int          *const_block;      ///< if true, this is a constant value block
    int          js_blocks;         ///< true if this block contains a difference signal
    unsigned int *shift_lsbs;       ///< shift of values for this block
    unsigned int *opt_order;        ///< prediction order of this block
    int          *store_prev_samples;///< if true, carryover samples have to be stored
    int          *use_ltp;          ///< if true, long-term prediction is used
    int          *ltp_lag;          ///< lag value for long-term prediction
    int          *ltp_gain;         ///< gain values for ltp 5-tap filter
    int32_t      *quant_cof;        ///< quantized parcor coefficients
    int32_t      *lpc_cof;          ///< coefficients of the direct form prediction
    int32_t      *raw_samples;      ///< decoded raw samples / residuals for this block
    int32_t      *prev_raw_samples; ///< contains unshifted raw samples from the previous block
    int32_t      *raw_other;        ///< decoded raw samples of the other channel of a channel pair
} ALSBlockData;
#ifdef DEBUG
#endif

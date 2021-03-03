#include <math.h>
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mem.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "put_bits.h"
#include "wmavoice_data.h"
#include "celp_filters.h"
#include "acelp_vectors.h"
#include "acelp_filters.h"
#include "lsp.h"
#include "dct.h"
#include "rdft.h"
#include "sinewin.h"
#define MAX_BLOCKS           8   ///< maximum number of blocks per frame
#define MAX_LSPS             16  ///< maximum filter order
#define MAX_LSPS_ALIGN16     16  ///< same as #MAX_LSPS; needs to be multiple
#define MAX_FRAMES           3   ///< maximum number of frames per superframe
#define MAX_FRAMESIZE        160 ///< maximum number of samples per frame
#define MAX_SIGNAL_HISTORY   416 ///< maximum excitation signal history
#define MAX_SFRAMESIZE       (MAX_FRAMESIZE * MAX_FRAMES)
#define SFRAME_CACHE_MAXSIZE 256 ///< maximum cache size for frame data that
#define VLC_NBITS            6   ///< number of bits to read per VLC iteration
typedef struct WMAVoiceContext {
    /**
     * @name Global values specified in the stream header / extradata or used all over.
     * @{
     */
    GetBitContext gb;             ///< packet bitreader. During decoder init,
                                  ///< it contains the extradata from the
                                  ///< demuxer. During decoding, it contains
                                  ///< packet data.
    int8_t vbm_tree[25];          ///< converts VLC codes to frame type

    int spillover_bitsize;        ///< number of bits used to specify
                                  ///< #spillover_nbits in the packet header
                                  ///< = ceil(log2(ctx->block_align << 3))
    int history_nsamples;         ///< number of samples in history for signal
                                  ///< prediction (through ACB)

    /* postfilter specific values */
    int do_apf;                   ///< whether to apply the averaged
                                  ///< projection filter (APF)
    int denoise_strength;         ///< strength of denoising in Wiener filter
                                  ///< [0-11]
    int denoise_tilt_corr;        ///< Whether to apply tilt correction to the
                                  ///< Wiener filter coefficients (postfilter)
    int dc_level;                 ///< Predicted amount of DC noise, based
                                  ///< on which a DC removal filter is used

    int lsps;                     ///< number of LSPs per frame [10 or 16]
    int lsp_q_mode;               ///< defines quantizer defaults [0, 1]
    int lsp_def_mode;             ///< defines different sets of LSP defaults
                                  ///< [0, 1]

    int min_pitch_val;            ///< base value for pitch parsing code
    int max_pitch_val;            ///< max value + 1 for pitch parsing
    int pitch_nbits;              ///< number of bits used to specify the
                                  ///< pitch value in the frame header
    int block_pitch_nbits;        ///< number of bits used to specify the
                                  ///< first block's pitch value
    int block_pitch_range;        ///< range of the block pitch
    int block_delta_pitch_nbits;  ///< number of bits used to specify the
                                  ///< delta pitch between this and the last
                                  ///< block's pitch value, used in all but
                                  ///< first block
    int block_delta_pitch_hrange; ///< 1/2 range of the delta (full range is
                                  ///< from -this to +this-1)
    uint16_t block_conv_table[4]; ///< boundaries for block pitch unit/scale
                                  ///< conversion

    /**
     * @}
#define log_range(var, assign) do { \
#undef log_range

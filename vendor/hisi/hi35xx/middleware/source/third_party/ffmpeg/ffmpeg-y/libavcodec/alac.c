#include <inttypes.h>
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "internal.h"
#include "thread.h"
#include "unary.h"
#include "mathops.h"
#include "alac_data.h"
#include "alacdsp.h"
#define ALAC_EXTRADATA_SIZE 36
typedef struct ALACContext {
    AVClass *class;
    AVCodecContext *avctx;
    GetBitContext gb;
    int channels;

    int32_t *predict_error_buffer[2];
    int32_t *output_samples_buffer[2];
    int32_t *extra_bits_buffer[2];

    uint32_t max_samples_per_frame;
    uint8_t  sample_size;
    uint8_t  rice_history_mult;
    uint8_t  rice_initial_history;
    uint8_t  rice_limit;
    int      sample_rate;

    int extra_bits;     /**< number of extra bits beyond 16-bit */
    int nb_samples;     /**< number of samples in the current frame */

    int direct_output;
    int extra_bit_bug;

    ALACDSPContext dsp;
} ALACContext;
#if HAVE_THREADS
#endif

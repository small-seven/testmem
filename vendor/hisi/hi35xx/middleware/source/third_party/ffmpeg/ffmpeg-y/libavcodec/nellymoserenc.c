#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mathematics.h"
#include "audio_frame_queue.h"
#include "avcodec.h"
#include "fft.h"
#include "internal.h"
#include "nellymoser.h"
#include "sinewin.h"
#define BITSTREAM_WRITER_LE
#include "put_bits.h"
#define POW_TABLE_SIZE (1<<11)
#define POW_TABLE_OFFSET 3
#define OPT_SIZE ((1<<15) + 3000)
typedef struct NellyMoserEncodeContext {
    AVCodecContext  *avctx;
    int             last_frame;
    AVFloatDSPContext *fdsp;
    FFTContext      mdct_ctx;
    AudioFrameQueue afq;
    DECLARE_ALIGNED(32, float, mdct_out)[NELLY_SAMPLES];
    DECLARE_ALIGNED(32, float, in_buff)[NELLY_SAMPLES];
    DECLARE_ALIGNED(32, float, buf)[3 * NELLY_BUF_LEN];     ///< sample buffer
    float           (*opt )[OPT_SIZE];
    uint8_t         (*path)[OPT_SIZE];
} NellyMoserEncodeContext;
#define find_best(val, table, LUT, LUT_add, LUT_size) \

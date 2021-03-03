#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "bswapdsp.h"
#include "canopus.h"
#include "get_bits.h"
#include "avcodec.h"
#include "internal.h"
#include "thread.h"
#define VLC_BITS 7
#define VLC_DEPTH 2
typedef struct CLLCContext {
    AVCodecContext *avctx;
    BswapDSPContext bdsp;

    uint8_t *swapped_buf;
    int      swapped_buf_size;
} CLLCContext;
#if HAVE_THREADS
#endif

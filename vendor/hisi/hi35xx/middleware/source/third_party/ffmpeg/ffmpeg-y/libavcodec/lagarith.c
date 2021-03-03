#include <inttypes.h>
#include "avcodec.h"
#include "get_bits.h"
#include "mathops.h"
#include "lagarithrac.h"
#include "lossless_videodsp.h"
#include "thread.h"
typedef struct LagarithContext {
    AVCodecContext *avctx;
    LLVidDSPContext llviddsp;
    int zeros;                  /**< number of consecutive zero bytes encountered */
    int zeros_rem;              /**< number of zero bytes remaining to output */
} LagarithContext;
#if HAVE_THREADS
#endif

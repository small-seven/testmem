#include <stdint.h>
#include "libavutil/imgutils.h"
#include "libavutil/intmath.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "unary.h"
#define NB_LEVELS 4
#define PIXLET_MAGIC 0xDEADBEEF
#define H 0
#define V 1
typedef struct SubBand {
    unsigned width, height;
    unsigned size;
    unsigned x, y;
} SubBand;
typedef struct PixletContext {
    AVClass *class;

    GetByteContext gb;
    GetBitContext bc;

    int levels;
    int depth;
    int w, h;

    int16_t *filter[2];
    int16_t *prediction;
    int64_t scaling[4][2][NB_LEVELS];
    SubBand band[4][NB_LEVELS * 3 + 1];
} PixletContext;
#if HAVE_THREADS
#endif /* HAVE_THREADS */

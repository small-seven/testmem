#include "libavcodec/get_bits.h"
#include "libavcodec/unary.h"
#include "apetag.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#define MKMPCTAG(a, b) ((a) | ((b) << 8))
#define TAG_MPCK MKTAG('M','P','C','K')
typedef struct MPCContext {
    int ver;
    int64_t header_pos;
    int64_t samples;

    int64_t apetag_start;
} MPCContext;

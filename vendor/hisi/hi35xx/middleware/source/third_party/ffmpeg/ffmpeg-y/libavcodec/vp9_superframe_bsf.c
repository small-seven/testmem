#include "libavutil/avassert.h"
#include "avcodec.h"
#include "bsf.h"
#include "get_bits.h"
#define MAX_CACHE 8
typedef struct VP9BSFContext {
    int n_cache;
    AVPacket *cache[MAX_CACHE];
} VP9BSFContext;
#define wloop(mag, wr) \

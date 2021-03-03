#include "libavutil/common.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct BFIContext {
    AVCodecContext *avctx;
    uint8_t *dst;
    uint32_t pal[256];
} BFIContext;

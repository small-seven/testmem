#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct QpegContext{
    AVCodecContext *avctx;
    AVFrame *pic, *ref;
    uint32_t pal[256];
    GetByteContext buffer;
} QpegContext;

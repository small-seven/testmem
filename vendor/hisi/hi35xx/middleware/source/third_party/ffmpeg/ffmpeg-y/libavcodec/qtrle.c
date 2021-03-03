#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct QtrleContext {
    AVCodecContext *avctx;
    AVFrame *frame;

    GetByteContext g;
    uint32_t pal[256];
} QtrleContext;
#define CHECK_PIXEL_PTR(n)                                                            \

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "internal.h"
#include "msrledec.h"
#include "libavutil/imgutils.h"
typedef struct MsrleContext {
    AVCodecContext *avctx;
    AVFrame *frame;

    GetByteContext gb;
    const unsigned char *buf;
    int size;

    uint32_t pal[256];
} MsrleContext;

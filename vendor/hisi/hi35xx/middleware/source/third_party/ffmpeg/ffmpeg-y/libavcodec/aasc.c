#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "internal.h"
#include "msrledec.h"
typedef struct AascContext {
    AVCodecContext *avctx;
    GetByteContext gb;
    AVFrame *frame;

    uint32_t palette[AVPALETTE_COUNT];
    int palette_size;
} AascContext;

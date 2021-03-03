#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
typedef struct EightBpsContext {
    AVCodecContext *avctx;

    unsigned char planes;
    unsigned char planemap[4];

    uint32_t pal[256];
} EightBpsContext;

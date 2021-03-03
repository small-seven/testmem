#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#define PALETTE_COUNT 256
#define CHECK_STREAM_PTR(n) \
typedef struct Msvideo1Context {

    AVCodecContext *avctx;
    AVFrame *frame;

    const unsigned char *buf;
    int size;

    int mode_8bit;  /* if it's not 8-bit, it's 16-bit */

    uint32_t pal[256];
} Msvideo1Context;

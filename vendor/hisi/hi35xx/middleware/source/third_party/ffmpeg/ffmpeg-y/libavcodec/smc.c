#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define CPAIR 2
#define CQUAD 4
#define COCTET 8
#define COLORS_PER_TABLE 256
typedef struct SmcContext {

    AVCodecContext *avctx;
    AVFrame *frame;

    GetByteContext gb;

    /* SMC color tables */
    unsigned char color_pairs[COLORS_PER_TABLE * CPAIR];
    unsigned char color_quads[COLORS_PER_TABLE * CQUAD];
    unsigned char color_octets[COLORS_PER_TABLE * COCTET];

    uint32_t pal[256];
} SmcContext;
#define GET_BLOCK_COUNT() \
#define ADVANCE_BLOCK() \

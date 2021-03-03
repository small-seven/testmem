#include <stdio.h>
#include <stdlib.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "bytestream.h"
typedef struct VmncContext {
    AVCodecContext *avctx;
    AVFrame *pic;

    int bpp;
    int bpp2;
    int bigendian;
    uint8_t pal[768];
    int width, height;
    GetByteContext gb;

    /* cursor data */
    int cur_w, cur_h;
    int cur_x, cur_y;
    int cur_hx, cur_hy;
    uint8_t *curbits, *curmask;
    uint8_t *screendta;
} VmncContext;

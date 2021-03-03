#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
typedef uint8_t cvid_codebook[12];

#define MAX_STRIPS      32

typedef struct cvid_strip {
    uint16_t          id;
    uint16_t          x1, y1;
    uint16_t          x2, y2;
    cvid_codebook     v4_codebook[256];
    cvid_codebook     v1_codebook[256];
} cvid_strip;
typedef struct CinepakContext {

    AVCodecContext *avctx;
    AVFrame *frame;

    const unsigned char *data;
    int size;

    int width, height;

    int palette_video;
    cvid_strip strips[MAX_STRIPS];

    int sega_film_skip_bytes;

    uint32_t pal[256];
} CinepakContext;

#include <stdio.h>
#include <stdlib.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct VBDecContext {
    AVCodecContext *avctx;

    uint8_t *frame, *prev_frame;
    uint32_t pal[AVPALETTE_COUNT];
    GetByteContext stream;
} VBDecContext;

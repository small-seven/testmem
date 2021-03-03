#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "ulti_cb.h"
typedef struct UltimotionDecodeContext {
    AVCodecContext *avctx;
    int width, height, blocks;
    AVFrame *frame;
    const uint8_t *ulti_codebook;
    GetByteContext gb;
} UltimotionDecodeContext;

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/internal.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct RpzaContext {

    AVCodecContext *avctx;
    AVFrame *frame;

    GetByteContext gb;
} RpzaContext;
#define CHECK_BLOCK()                                                         \
#define ADVANCE_BLOCK()             \

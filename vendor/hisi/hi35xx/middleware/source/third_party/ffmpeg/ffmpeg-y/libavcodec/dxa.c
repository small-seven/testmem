#include <stdio.h>
#include <stdlib.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "bytestream.h"
#include "avcodec.h"
#include "internal.h"
#include <zlib.h>
typedef struct DxaDecContext {
    AVFrame *prev;

    int dsize;
#define DECOMP_BUF_PADDING 16
    uint8_t *decomp_buf;
    uint32_t pal[256];
} DxaDecContext;

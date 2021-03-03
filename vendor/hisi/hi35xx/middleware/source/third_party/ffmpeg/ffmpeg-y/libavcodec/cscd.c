#include <stdio.h>
#include <stdlib.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/common.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "libavutil/lzo.h"
typedef struct CamStudioContext {
    AVFrame *pic;
    int linelen, height, bpp;
    unsigned int decomp_size;
    unsigned char* decomp_buf;
} CamStudioContext;
#if CONFIG_ZLIB
#else
#endif

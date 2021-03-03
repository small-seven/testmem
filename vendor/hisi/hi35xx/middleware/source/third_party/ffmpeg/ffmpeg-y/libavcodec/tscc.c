#include <stdio.h>
#include <stdlib.h>
#include "avcodec.h"
#include "internal.h"
#include "msrledec.h"
#include <zlib.h>
typedef struct TsccContext {

    AVCodecContext *avctx;
    AVFrame *frame;

    // Bits per pixel
    int bpp;
    // Decompressed data size
    unsigned int decomp_size;
    // Decompression buffer
    unsigned char* decomp_buf;
    GetByteContext gb;
    int height;
    z_stream zstream;

    uint32_t pal[256];
} CamtasiaContext;

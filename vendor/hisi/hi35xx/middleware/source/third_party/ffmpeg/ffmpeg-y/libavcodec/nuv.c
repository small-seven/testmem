#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lzo.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "idctdsp.h"
#include "internal.h"
#include "rtjpeg.h"
typedef struct NuvContext {
    AVFrame *pic;
    int codec_frameheader;
    int quality;
    int width, height;
    unsigned int decomp_size;
    unsigned char *decomp_buf;
    uint32_t lq[64], cq[64];
    RTJpegContext rtj;
} NuvContext;

#include <stdio.h>
#include <stdlib.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include <zlib.h>
#define ZMBV_KEYFRAME 1
#define ZMBV_DELTAPAL 2
#define ZMBV_BLOCK 16
typedef struct ZmbvEncContext {
    AVCodecContext *avctx;

    int lrange, urange;
    uint8_t *comp_buf, *work_buf;
    uint8_t pal[768];
    uint32_t pal2[256]; //for quick comparisons
    uint8_t *prev, *prev_buf;
    int pstride;
    int comp_size;
    int keyint, curfrm;
    int bypp;
    enum ZmbvFormat fmt;
    z_stream zstream;

    int score_tab[ZMBV_BLOCK * ZMBV_BLOCK * 4 + 1];
} ZmbvEncContext;
#if FF_API_CODED_FRAME
#endif
#ifdef ZMBV_ENABLE_24BPP
#endif //ZMBV_ENABLE_24BPP
#ifdef ZMBV_ENABLE_24BPP
#endif //ZMBV_ENABLE_24BPP

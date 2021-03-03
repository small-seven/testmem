#include <stdio.h>
#include <stdlib.h>
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include <zlib.h>
#define ZMBV_KEYFRAME 1
#define ZMBV_DELTAPAL 2
typedef struct ZmbvContext {
    AVCodecContext *avctx;

    int bpp;
    int alloc_bpp;
    unsigned int decomp_size;
    uint8_t* decomp_buf;
    uint8_t pal[768];
    uint8_t *prev, *cur;
    int width, height;
    int fmt;
    int comp;
    int flags;
    int stride;
    int bw, bh, bx, by;
    int decomp_len;
    z_stream zstream;
    int (*decode_intra)(struct ZmbvContext *c);
    int (*decode_xor)(struct ZmbvContext *c);
} ZmbvContext;
#ifdef ZMBV_ENABLE_24BPP
#endif //ZMBV_ENABLE_24BPP
#ifdef ZMBV_ENABLE_24BPP
#endif //ZMBV_ENABLE_24BPP
#ifdef ZMBV_ENABLE_24BPP
#endif

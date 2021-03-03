#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
typedef struct BlockInfo {
    uint8_t *pos;
    int      size;
} BlockInfo;
typedef struct FlashSVContext {
    AVCodecContext *avctx;
    AVFrame        *frame;
    int             image_width, image_height;
    int             block_width, block_height;
    uint8_t        *tmpblock;
    int             block_size;
    z_stream        zstream;
    int             ver;
    const uint32_t *pal;
    int             is_keyframe;
    uint8_t        *keyframedata;
    uint8_t        *keyframe;
    BlockInfo      *blocks;
    uint8_t        *deflate_block;
    int             deflate_block_size;
    int             color_depth;
    int             zlibprime_curr, zlibprime_prev;
    int             diff_start, diff_height;
} FlashSVContext;
#if CONFIG_FLASHSV_DECODER
#endif /* CONFIG_FLASHSV_DECODER */
#if CONFIG_FLASHSV2_DECODER
#endif /* CONFIG_FLASHSV2_DECODER */

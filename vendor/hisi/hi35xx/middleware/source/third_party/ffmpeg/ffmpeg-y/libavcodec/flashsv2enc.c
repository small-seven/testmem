#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#include "bytestream.h"
#define HAS_IFRAME_IMAGE 0x02
#define HAS_PALLET_INFO 0x01
#define COLORSPACE_BGR 0x00
#define COLORSPACE_15_7 0x10
#define HAS_DIFF_BLOCKS 0x04
#define ZLIB_PRIME_COMPRESS_CURRENT 0x02
#define ZLIB_PRIME_COMPRESS_PREVIOUS 0x01
#define FLASHSV2_DUMB
typedef struct Block {
    uint8_t *enc;
    uint8_t *sl_begin, *sl_end;
    int enc_size;
    uint8_t *data;
    unsigned long data_size;

    uint8_t start, len;
    uint8_t dirty;
    uint8_t col, row, width, height;
    uint8_t flags;
} Block;
typedef struct Palette {
    unsigned colors[128];
    uint8_t index[1 << 15];
} Palette;
typedef struct FlashSV2Context {
    AVCodecContext *avctx;
    uint8_t *current_frame;
    uint8_t *key_frame;
    uint8_t *encbuffer;
    uint8_t *keybuffer;
    uint8_t *databuffer;

    uint8_t *blockbuffer;
    int blockbuffer_size;

    Block *frame_blocks;
    Block *key_blocks;
    int frame_size;
    int blocks_size;

    int use15_7, dist, comp;

    int rows, cols;

    int last_key_frame;

    int image_width, image_height;
    int block_width, block_height;
    uint8_t flags;
    uint8_t use_custom_palette;
    uint8_t palette_type;       ///< 0=>default, 1=>custom - changed when palette regenerated.
    Palette palette;
#ifndef FLASHSV2_DUMB
    double tot_blocks;          ///< blocks encoded since last keyframe
    double diff_blocks;         ///< blocks that were different since last keyframe
    double tot_lines;           ///< total scanlines in image since last keyframe
    double diff_lines;          ///< scanlines that were different since last keyframe
    double raw_size;            ///< size of raw frames since last keyframe
    double comp_size;           ///< size of compressed data since last keyframe
    double uncomp_size;         ///< size of uncompressed data since last keyframe

    double total_bits;          ///< total bits written to stream so far
#endif
} FlashSV2Context;
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#endif
#define ABSDIFF(a,b) (abs((int)(a)-(int)(b)))
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#else
#endif
#ifndef FLASHSV2_DUMB
#endif
#ifndef FLASHSV2_DUMB
#else
#endif
#ifndef FLASHSV2_DUMB
#else
#endif
#ifndef FLASHSV2_DUMB
#else
#endif
#ifndef FLASHSV2_DUMB
#else
#endif

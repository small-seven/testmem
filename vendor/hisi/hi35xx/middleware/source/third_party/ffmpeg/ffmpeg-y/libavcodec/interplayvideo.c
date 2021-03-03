#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "hpeldsp.h"
#include "internal.h"
#define PALETTE_COUNT 256
typedef struct IpvideoContext {

    AVCodecContext *avctx;
    HpelDSPContext hdsp;
    AVFrame *second_last_frame;
    AVFrame *last_frame;

    /* For format 0x10 */
    AVFrame *cur_decode_frame;
    AVFrame *prev_decode_frame;

    const unsigned char *decoding_map;
    int decoding_map_size;
    const unsigned char *skip_map;
    int skip_map_size;

    int is_16bpp;
    GetByteContext stream_ptr, mv_ptr;
    unsigned char *pixel_ptr;
    int line_inc;
    int stride;
    int upper_motion_limit_offset;

    uint32_t pal[256];
} IpvideoContext;

#include <inttypes.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "unary.h"
typedef int (*decode_slice_func)(GetBitContext *gb, AVFrame *frame,
                                 int line, int height, uint8_t lru[3][8]);

typedef void (*setup_lru_func)(uint8_t lru[3][8]);

static int dxtory_decode_v2(AVCodecContext *avctx, AVFrame *pic,
                            const uint8_t *src, int src_size,
                            decode_slice_func decode_slice,
                            setup_lru_func setup_lru,
                            enum AVPixelFormat fmt)
{
    GetByteContext gb, gb_check;
    GetBitContext  gb2;
    int nslices, slice, line = 0;
    uint32_t off, slice_size;
    uint64_t off_check;
    uint8_t lru[3][8];
    int ret;

    ret = load_buffer(avctx, src, src_size, &gb, &nslices, &off);
    if (ret < 0)
        return ret;

    off_check = off;
    gb_check = gb;
    for (slice = 0; slice < nslices; slice++) {
        slice_size = bytestream2_get_le32(&gb_check);

        if (slice_size <= 16 + (avctx->height * avctx->width / (8 * nslices)))
            return AVERROR_INVALIDDATA;
        off_check += slice_size;
    }

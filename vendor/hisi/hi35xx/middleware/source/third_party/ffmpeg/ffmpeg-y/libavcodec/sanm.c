#include "libavutil/avassert.h"
#include "libavutil/bswap.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "copy_block.h"
#include "internal.h"
#define NGLYPHS 256
#define GLYPH_COORD_VECT_SIZE 16
#define PALETTE_SIZE 256
#define PALETTE_DELTA 768
typedef struct SANMVideoContext {
    AVCodecContext *avctx;
    GetByteContext gb;

    int version, subversion;
    uint32_t pal[PALETTE_SIZE];
    int16_t delta_pal[PALETTE_DELTA];

    ptrdiff_t pitch;
    int width, height;
    int aligned_width, aligned_height;
    int prev_seq;

    AVFrame *frame;
    uint16_t *frm0, *frm1, *frm2;
    uint8_t *stored_frame;
    uint32_t frm0_size, frm1_size, frm2_size;
    uint32_t stored_frame_size;

    uint8_t *rle_buf;
    unsigned int rle_buf_size;

    int rotate_code;

    long npixels, buf_size;

    uint16_t codebook[256];
    uint16_t small_codebook[4];

    int8_t p4x4glyphs[NGLYPHS][16];
    int8_t p8x8glyphs[NGLYPHS][64];
} SANMVideoContext;
typedef struct SANMFrameHeader {
    int seq_num, codec, rotate_code, rle_output_size;

    uint16_t bg_color;
    uint32_t width, height;
} SANMFrameHeader;
#if HAVE_BIGENDIAN
#endif
#if HAVE_BIGENDIAN
#endif
typedef int (*frm_decoder)(SANMVideoContext *ctx);

static const frm_decoder v1_decoders[] = {
    decode_0, decode_nop, decode_2, decode_3, decode_4, decode_5,
    decode_6, decode_nop, decode_8
};

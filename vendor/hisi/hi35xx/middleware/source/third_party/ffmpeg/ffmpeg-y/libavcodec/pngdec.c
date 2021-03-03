#include "libavutil/avassert.h"
#include "libavutil/bprint.h"
#include "libavutil/imgutils.h"
#include "libavutil/stereo3d.h"
#include "libavutil/mastering_display_metadata.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "apng.h"
#include "png.h"
#include "pngdsp.h"
#include "thread.h"
#include <zlib.h>
typedef struct PNGDecContext {
    PNGDSPContext dsp;
    AVCodecContext *avctx;

    GetByteContext gb;
    ThreadFrame previous_picture;
    ThreadFrame last_picture;
    ThreadFrame picture;

    enum PNGHeaderState hdr_state;
    enum PNGImageState pic_state;
    int width, height;
    int cur_w, cur_h;
    int last_w, last_h;
    int x_offset, y_offset;
    int last_x_offset, last_y_offset;
    uint8_t dispose_op, blend_op;
    uint8_t last_dispose_op;
    int bit_depth;
    int color_type;
    int compression_type;
    int interlace_type;
    int filter_type;
    int channels;
    int bits_per_pixel;
    int bpp;
    int has_trns;
    uint8_t transparent_color_be[6];

    uint8_t *image_buf;
    int image_linesize;
    uint32_t palette[256];
    uint8_t *crow_buf;
    uint8_t *last_row;
    unsigned int last_row_size;
    uint8_t *tmp_row;
    unsigned int tmp_row_size;
    uint8_t *buffer;
    int buffer_size;
    int pass;
    int crow_size; /* compressed row size (include filter type) */
    int row_size; /* decompressed row size */
    int pass_row_size; /* decompress row size of the current pass */
    int y;
    z_stream zstream;
} PNGDecContext;
#define UNROLL1(bpp, op)                                                      \
#define UNROLL_FILTER(op)                                                     \
#define OP_SUB(x, s, l) ((x) + (s))
#define OP_AVG(x, s, l) (((((x) + (l)) >> 1) + (s)) & 0xff)
#define YUV2RGB(NAME, TYPE) \
#define FAST_DIV255(x) ((((x) + 128) * 257) >> 16)
#if CONFIG_PNG_DECODER
#endif
#if CONFIG_APNG_DECODER
#endif
#if CONFIG_LSCR_DECODER
#endif
#if HAVE_THREADS
#endif
#if CONFIG_APNG_DECODER
#endif
#if CONFIG_PNG_DECODER
#endif
#if CONFIG_LSCR_DECODER
#endif

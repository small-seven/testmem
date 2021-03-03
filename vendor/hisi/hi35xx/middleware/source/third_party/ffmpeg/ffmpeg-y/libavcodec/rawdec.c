#include "avcodec.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "internal.h"
#include "raw.h"
#include "libavutil/avassert.h"
#include "libavutil/buffer.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
typedef struct RawVideoContext {
    AVClass *av_class;
    AVBufferRef *palette;
    int frame_size;  /* size of the frame in bytes */
    int flip;
    int is_1_2_4_8_bpp; // 1, 2, 4 and 8 bpp in avi/mov, 1 and 8 bpp in nut
    int is_mono;
    int is_pal8;
    int is_nut_mono;
    int is_nut_pal8;
    int is_yuv2;
    int is_lt_16bpp; // 16bpp pixfmt and bits_per_coded_sample < 16
    int tff;

    BswapDSPContext bbdsp;
    void *bitstream_buf;
    unsigned int bitstream_buf_size;
} RawVideoContext;
#if FF_API_PSEUDOPAL
#endif
#define SCALE16(x, bits) (((x) << (16 - (bits))) | ((x) >> (2 * (bits) - 16)))
#define MKSCALE16(name, r16, w16) \

#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "config.h"
#include "swscale.h"
#include "swscale_internal.h"
#include "rgb2rgb.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/cpu.h"
#include "libavutil/avutil.h"
#include "libavutil/mathematics.h"
#include "libavutil/bswap.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avassert.h"
#include "libavutil/avconfig.h"
#if AV_HAVE_BIGENDIAN
#define output_pixel(p, v) do { \
#else
#define output_pixel(p, v) (*p) = (v)
#endif
#undef output_pixel
#define BAYER_GBRG
#define BAYER_8
#define BAYER_RENAME(x) bayer_gbrg8_to_##x
#include "bayer_template.c"
#define BAYER_GBRG
#define BAYER_16LE
#define BAYER_RENAME(x) bayer_gbrg16le_to_##x
#include "bayer_template.c"
#define BAYER_GBRG
#define BAYER_16BE
#define BAYER_RENAME(x) bayer_gbrg16be_to_##x
#include "bayer_template.c"
#define BAYER_GRBG
#define BAYER_8
#define BAYER_RENAME(x) bayer_grbg8_to_##x
#include "bayer_template.c"
#define BAYER_GRBG
#define BAYER_16LE
#define BAYER_RENAME(x) bayer_grbg16le_to_##x
#include "bayer_template.c"
#define BAYER_GRBG
#define BAYER_16BE
#define BAYER_RENAME(x) bayer_grbg16be_to_##x
#include "bayer_template.c"
#define BAYER_BGGR
#define BAYER_8
#define BAYER_RENAME(x) bayer_bggr8_to_##x
#include "bayer_template.c"
#define BAYER_BGGR
#define BAYER_16LE
#define BAYER_RENAME(x) bayer_bggr16le_to_##x
#include "bayer_template.c"
#define BAYER_BGGR
#define BAYER_16BE
#define BAYER_RENAME(x) bayer_bggr16be_to_##x
#include "bayer_template.c"
#define BAYER_RGGB
#define BAYER_8
#define BAYER_RENAME(x) bayer_rggb8_to_##x
#include "bayer_template.c"
#define BAYER_RGGB
#define BAYER_16LE
#define BAYER_RENAME(x) bayer_rggb16le_to_##x
#include "bayer_template.c"
#define BAYER_RGGB
#define BAYER_16BE
#define BAYER_RENAME(x) bayer_rggb16be_to_##x
#include "bayer_template.c"
#define CASE(pixfmt, prefix) \
#undef CASE
#define CASE(pixfmt, prefix) \
#undef CASE
#define isRGBA32(x) (            \
#define isRGBA64(x) (                \
#define isRGB48(x) (                \
typedef void (* rgbConvFn) (const uint8_t *, uint8_t *, int);
static rgbConvFn findRgbConvFn(SwsContext *c)
{
    const enum AVPixelFormat srcFormat = c->srcFormat;
    const enum AVPixelFormat dstFormat = c->dstFormat;
    const int srcId = c->srcFormatBpp;
    const int dstId = c->dstFormatBpp;
    rgbConvFn conv = NULL;

#define IS_NOT_NE(bpp, desc) \
    (((bpp + 7) >> 3) == 2 && \
     (!(desc->flags & AV_PIX_FMT_FLAG_BE) != !HAVE_BIGENDIAN))

#define CONV_IS(src, dst) (srcFormat == AV_PIX_FMT_##src && dstFormat == AV_PIX_FMT_##dst)

    if (isRGBA32(srcFormat) && isRGBA32(dstFormat)) {
        if (     CONV_IS(ABGR, RGBA)
              || CONV_IS(ARGB, BGRA)
              || CONV_IS(BGRA, ARGB)
              || CONV_IS(RGBA, ABGR)) conv = shuffle_bytes_3210;
        else if (CONV_IS(ABGR, ARGB)
              || CONV_IS(ARGB, ABGR)) conv = shuffle_bytes_0321;
        else if (CONV_IS(ABGR, BGRA)
              || CONV_IS(ARGB, RGBA)) conv = shuffle_bytes_1230;
        else if (CONV_IS(BGRA, RGBA)
              || CONV_IS(RGBA, BGRA)) conv = shuffle_bytes_2103;
        else if (CONV_IS(BGRA, ABGR)
              || CONV_IS(RGBA, ARGB)) conv = shuffle_bytes_3012;
    } else if (isRGB48(srcFormat) && isRGB48(dstFormat)) {
#define DITHER_COPY(dst, dstStride, src, srcStride, bswap, dbswap)\
#if HAVE_FAST_64BIT
#define FAST_COPY_UP(shift) \
#else
#define FAST_COPY_UP(shift) \
#endif
#define COPY_UP(r,w) \
#define IS_DIFFERENT_ENDIANESS(src_fmt, dst_fmt, pix_fmt)          \
#define isByteRGB(f) (             \
#define isPlanarGray(x) (isGray(x) && (x) != AV_PIX_FMT_YA8 && (x) != AV_PIX_FMT_YA16LE && (x) != AV_PIX_FMT_YA16BE)

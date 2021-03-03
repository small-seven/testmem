#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/avutil.h"
#include "libavutil/avassert.h"
#include "libavutil/bswap.h"
#include "libavutil/cpu.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "config.h"
#include "rgb2rgb.h"
#include "swscale.h"
#include "swscale_internal.h"
#if 1
#elif 1
#elif 1
#else
#endif
#define output_pixel(pos, val, bias, signedness) \
#define yuv2plane1_float(template, dest_type, BE_LE) \
#define yuv2planeX_float(template, dest_type, BE_LE) \
#if HAVE_BIGENDIAN
#else
#endif
#undef output_pixel
#define output_pixel(pos, val) \
#undef output_pixel
#define yuv2NBPS(bits, BE_LE, is_be, template_size, typeX_t) \
#define output_pixel(pos, val) \
#undef output_pixel
#define accumulate_bit(acc, val) \
#define output_pixel(pos, acc) \
#undef output_pixel
#undef accumulate_bit
#define YUV2PACKEDWRAPPER(name, base, ext, fmt) \
#define output_pixels(pos, Y1, U, Y2, V) \
#undef output_pixels
#define R_B ((target == AV_PIX_FMT_RGB48LE || target == AV_PIX_FMT_RGB48BE || target == AV_PIX_FMT_RGBA64LE || target == AV_PIX_FMT_RGBA64BE) ? R : B)
#define B_R ((target == AV_PIX_FMT_RGB48LE || target == AV_PIX_FMT_RGB48BE || target == AV_PIX_FMT_RGBA64LE || target == AV_PIX_FMT_RGBA64BE) ? B : R)
#define output_pixel(pos, val) \
#undef output_pixel
#undef r_b
#undef b_r
#define YUV2PACKED16WRAPPER(name, base, ext, fmt, hasAlpha, eightbytes) \
#if CONFIG_SMALL
#else
#if defined(ASSERT_LEVEL) && ASSERT_LEVEL > 1
#endif
#endif
#define r_b ((target == AV_PIX_FMT_RGB24) ? r : b)
#define b_r ((target == AV_PIX_FMT_RGB24) ? b : r)
#undef r_b
#undef b_r
#define YUV2RGBWRAPPERX(name, base, ext, fmt, hasAlpha) \
#define YUV2RGBWRAPPERX2(name, base, ext, fmt, hasAlpha) \
#define YUV2RGBWRAPPER(name, base, ext, fmt, hasAlpha) \
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif
#endif
#define A_DITHER(u,v)   (((((u)+((v)*236))*119)&0xff))
#define X_DITHER(u,v)   (((((u)^((v)*237))*181)&0x1ff)/2)
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif
#endif
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */
#if CONFIG_SMALL
#else
#if CONFIG_SWSCALE_ALPHA
#endif /* CONFIG_SWSCALE_ALPHA */
#endif /* !CONFIG_SMALL */

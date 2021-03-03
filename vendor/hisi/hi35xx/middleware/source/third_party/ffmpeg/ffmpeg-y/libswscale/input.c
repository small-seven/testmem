#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/avutil.h"
#include "libavutil/bswap.h"
#include "libavutil/cpu.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avassert.h"
#include "config.h"
#include "rgb2rgb.h"
#include "swscale.h"
#include "swscale_internal.h"
#define input_pixel(pos) (isBE(origin) ? AV_RB16(pos) : AV_RL16(pos))
#define r ((origin == AV_PIX_FMT_BGR48BE || origin == AV_PIX_FMT_BGR48LE || origin == AV_PIX_FMT_BGRA64BE || origin == AV_PIX_FMT_BGRA64LE) ? b_r : r_b)
#define b ((origin == AV_PIX_FMT_BGR48BE || origin == AV_PIX_FMT_BGR48LE || origin == AV_PIX_FMT_BGRA64BE || origin == AV_PIX_FMT_BGRA64LE) ? r_b : b_r)
#define rgb64funcs(pattern, BE_LE, origin) \
#undef r
#undef b
#undef input_pixel
#define rgb48funcs(pattern, BE_LE, origin)                              \
#define input_pixel(i) ((origin == AV_PIX_FMT_RGBA ||                      \
#undef input_pixel
#define rgb16_32_wrapper(fmt, name, shr, shg, shb, shp, maskr,          \
#define input_pixel(pos) (isBE(origin) ? AV_RB16(pos) : AV_RL16(pos))
#define rdpx(src) \
#undef rdpx
#define rgb9plus_planar_funcs_endian(nbits, endian_name, endian)                                    \
#define rgb9plus_planar_transparency_funcs(nbits)                           \
#define rgb9plus_planar_funcs(nbits)            \
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif

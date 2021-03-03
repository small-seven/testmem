#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "config.h"
#include "libswscale/rgb2rgb.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/pixdesc.h"
#include "yuv2rgb_altivec.h"
#if HAVE_ALTIVEC
#undef PROFILE_THE_BEAST
#undef INC_SCALING
typedef unsigned char ubyte;
typedef signed char   sbyte;

/* RGB interleaver, 16 planar pels 8-bit samples per channel in
 * homogeneous vector registers x0,x1,x2 are interleaved with the
 * following technique:
 *
 *    o0 = vec_mergeh(x0, x1);
 *    o1 = vec_perm(o0, x2, perm_rgb_0);
 *    o2 = vec_perm(o0, x2, perm_rgb_1);
 *    o3 = vec_mergel(x0, x1);
 *    o4 = vec_perm(o3, o2, perm_rgb_2);
 *    o5 = vec_perm(o3, o2, perm_rgb_3);
 *
 * perm_rgb_0:   o0(RG).h v1(B) --> o1*
 *            0   1  2   3   4
 *           rgbr|gbrg|brgb|rgbr
 *           0010 0100 1001 0010
 *           0102 3145 2673 894A
 *
 * perm_rgb_1:   o0(RG).h v1(B) --> o2
 *            0   1  2   3   4
 *           gbrg|brgb|bbbb|bbbb
 *           0100 1001 1111 1111
 *           B5CD 6EF7 89AB CDEF
 *
 * perm_rgb_2:   o3(RG).l o2(rgbB.l) --> o4*
 *            0   1  2   3   4
 *           gbrg|brgb|rgbr|gbrg
 *           1111 1111 0010 0100
 *           89AB CDEF 0182 3945
 *
 * perm_rgb_2:   o3(RG).l o2(rgbB.l) ---> o5*
 *            0   1  2   3   4
 *           brgb|rgbr|gbrg|brgb
 *           1001 0010 0100 1001
 *           a67b 89cA BdCD eEFf
 */
static const vector unsigned char
    perm_rgb_0 = { 0x00, 0x01, 0x10, 0x02, 0x03, 0x11, 0x04, 0x05,
                   0x12, 0x06, 0x07, 0x13, 0x08, 0x09, 0x14, 0x0a },
#define vec_merge3(x2, x1, x0, y0, y1, y2)     \
#define vec_mstbgr24(x0, x1, x2, ptr)          \
#define vec_mstrgb24(x0, x1, x2, ptr)          \
#define vec_mstrgb32(T, x0, x1, x2, x3, ptr)                            \
#if HAVE_BIGENDIAN
#define vec_unh(x)                                                      \
#define vec_unl(x)                                                      \
#else
#define vec_unh(x)(vector signed short) vec_mergeh(x,(__typeof__(x)) { 0 })
#define vec_unl(x)(vector signed short) vec_mergel(x,(__typeof__(x)) { 0 })
#endif
#define vec_clip_s16(x)                                                 \
#define vec_packclp(x, y)                                               \
#define DEFCSP420_CVT(name, out_pixels)                                       \
#define out_abgr(a, b, c, ptr)                                          \
#define out_bgra(a, b, c, ptr)                                          \
#define out_rgba(a, b, c, ptr)                                          \
#define out_argb(a, b, c, ptr)                                          \
#define out_rgb24(a, b, c, ptr) vec_mstrgb24(a, b, c, ptr)
#define out_bgr24(a, b, c, ptr) vec_mstbgr24(a, b, c, ptr)
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#define YUV2PACKEDX_WRAPPER(suffix, pixfmt)                             \
#endif /* HAVE_ALTIVEC */

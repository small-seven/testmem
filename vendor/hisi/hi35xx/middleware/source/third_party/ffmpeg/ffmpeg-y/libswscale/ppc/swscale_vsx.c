#include <inttypes.h>
#include "config.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "yuv2rgb_altivec.h"
#include "libavutil/ppc/util_altivec.h"
#if HAVE_VSX
#define vzero vec_splat_s32(0)
#if !HAVE_BIGENDIAN
#define  GET_LS(a,b,c,s) {\
#define yuv2planeX_8(d1, d2, l1, src, x, perm, filter) do {\
#define LOAD_FILTER(vf,f) {\
#define LOAD_L1(ll1,s,p){\
#define GET_VF4(a, vf, f) {\
#define FIRST_LOAD(sv, pos, s, per) {}
#define UPDATE_PTR(s0, d0, s1, d1) {}
#define LOAD_SRCV(pos, a, s, per, v0, v1, vf) {\
#define LOAD_SRCV8(pos, a, s, per, v0, v1, vf) LOAD_SRCV(pos, a, s, per, v0, v1, vf)
#define GET_VFD(a, b, f, vf0, vf1, per, vf, off) {\
#define FUNC(name) name ## _vsx
#include "swscale_ppc_template.c"
#undef FUNC
#undef vzero
#endif /* !HAVE_BIGENDIAN */
#if !HAVE_BIGENDIAN
#define output_pixel(pos, val) \
#undef output_pixel
#define output_pixel(pos, val, bias, signedness) \
#if HAVE_POWER8
#endif /* HAVE_POWER8 */
#define yuv2NBPS(bits, BE_LE, is_be, template_size, typeX_t) \
#define yuv2NBPS1(bits, BE_LE, is_be, template_size, typeX_t) \
#define yuv2NBPSX(bits, BE_LE, is_be, template_size, typeX_t) \
#if HAVE_POWER8
#endif
#define WRITERGB \
#define SETUP(x, buf0, alpha1, buf1, alpha) { \
#undef SETUP
#undef WRITERGB
#define YUV2RGBWRAPPERX(name, base, ext, fmt, hasAlpha) \
#define YUV2RGBWRAPPERX2(name, base, ext, fmt, hasAlpha) \
#define YUV2RGBWRAPPER(name, base, ext, fmt, hasAlpha) \
#define SETUP(x, buf0, buf1, alpha) { \
#undef SETUP
#define YUV2PACKEDWRAPPERX(name, base, ext, fmt) \
#define YUV2PACKEDWRAPPER2(name, base, ext, fmt) \
#define YUV2PACKEDWRAPPER(name, base, ext, fmt) \
#define HCSCALE(in, out) \
#undef HCSCALE
#endif /* !HAVE_BIGENDIAN */
#endif /* HAVE_VSX */
#if HAVE_VSX
#if !HAVE_BIGENDIAN
#endif
#if !HAVE_BIGENDIAN
#if HAVE_POWER8
#endif /* HAVE_POWER8 */
#endif /* !HAVE_BIGENDIAN */
#if !HAVE_BIGENDIAN
#endif /* !HAVE_BIGENDIAN */
#endif /* HAVE_VSX */

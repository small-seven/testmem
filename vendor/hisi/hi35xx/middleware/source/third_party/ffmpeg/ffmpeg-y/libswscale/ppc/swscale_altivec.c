#include <inttypes.h>
#include "config.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "yuv2rgb_altivec.h"
#include "libavutil/ppc/util_altivec.h"
#if HAVE_ALTIVEC
#if HAVE_BIGENDIAN
#define vzero vec_splat_s32(0)
#define  GET_LS(a,b,c,s) {\
#define yuv2planeX_8(d1, d2, l1, src, x, perm, filter) do {\
#define LOAD_FILTER(vf,f) {\
#define LOAD_L1(ll1,s,p){\
#define GET_VF4(a, vf, f) {\
#define FIRST_LOAD(sv, pos, s, per) {\
#define UPDATE_PTR(s0, d0, s1, d1) {\
#define LOAD_SRCV(pos, a, s, per, v0, v1, vf) {\
#define LOAD_SRCV8(pos, a, s, per, v0, v1, vf) {\
#define GET_VFD(a, b, f, vf0, vf1, per, vf, off) {\
#define FUNC(name) name ## _altivec
#include "swscale_ppc_template.c"
#undef FUNC
#undef vzero
#endif /* HAVE_BIGENDIAN */
#define output_pixel(pos, val, bias, signedness) \
#define yuv2plane1_float(template, dest_type, BE_LE) \
#if HAVE_BIGENDIAN
#else
#endif
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#if HAVE_BIGENDIAN
#endif
#endif /* HAVE_ALTIVEC */

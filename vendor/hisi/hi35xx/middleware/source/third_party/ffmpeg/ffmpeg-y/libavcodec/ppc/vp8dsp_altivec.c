#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/vp8dsp.h"
#include "hpeldsp_altivec.h"
#if HAVE_ALTIVEC
#define REPT4(...) { __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__ }
#define LOAD_H_SUBPEL_FILTER(i) \
#if HAVE_BIGENDIAN
#define GET_PIXHL(offset)                   \
#define GET_OUTER(offset) outer = vec_perm(a, b, perm_6tap##offset)
#else
#define GET_PIXHL(offset)                   \
#define GET_OUTER(offset) outer = vec_perm(a, a, perm_outer)
#endif
#define FILTER_H(dstv, off) \
#if HAVE_BIGENDIAN
#endif
#if HAVE_BIGENDIAN
#endif
#define LOAD_V_SUBPEL_FILTER(i) \
#define FILTER_V(dstv, vec_mul) \
#if HAVE_BIGENDIAN
#define LOAD_HL(off, s, perm) load_with_perm_vec(off, s, perm)
#else
#define LOAD_HL(off, s, perm) vec_mergeh(vec_vsx_ld(off,s), vec_vsx_ld(off+8,s))
#endif
#if HAVE_BIGENDIAN
#endif
#define EPEL_FUNCS(WIDTH, TAPS) \
#define EPEL_HV(WIDTH, HTAPS, VTAPS) \
#if HAVE_BIGENDIAN
#endif
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */

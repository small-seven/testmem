#include "libavutil/mem.h"
#include "libavutil/ppc/util_altivec.h"
#define CHROMA_MC8_ALTIVEC_CORE(BIAS1, BIAS2) \
#define CHROMA_MC8_ALTIVEC_CORE_SIMPLE \
#define noop(a) a
#define add28(a) vec_add(v28ss, a)
#if HAVE_BIGENDIAN
#define GET_VSRC1(vs0, off, b, perm0, s){    \
#define GET_VSRC(vs0, vs1, off, b, perm0, perm1, s){ \
#else
#define GET_VSRC1(vs0, off, b, perm0, s){            \
#define GET_VSRC(vs0, vs1, off, b, perm0, perm1, s){ \
#endif /* HAVE_BIGENDIAN */
#ifdef PREFIX_h264_chroma_mc8_altivec
#if HAVE_BIGENDIAN
#endif
#endif
#ifdef PREFIX_no_rnd_vc1_chroma_mc8_altivec
#if HAVE_BIGENDIAN
#endif
#endif
#undef noop
#undef add28
#undef CHROMA_MC8_ALTIVEC_CORE

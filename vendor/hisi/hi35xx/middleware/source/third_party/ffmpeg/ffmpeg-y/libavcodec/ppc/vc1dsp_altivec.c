#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/vc1dsp.h"
#if HAVE_ALTIVEC
#define STEP8(s0, s1, s2, s3, s4, s5, s6, s7, vec_rnd) \
#define SHIFT_HOR8(s0, s1, s2, s3, s4, s5, s6, s7) \
#define SHIFT_VERT8(s0, s1, s2, s3, s4, s5, s6, s7) \
#define STEP4(s0, s1, s2, s3, vec_rnd) \
#define SHIFT_HOR4(s0, s1, s2, s3) \
#define SHIFT_VERT4(s0, s1, s2, s3) \
#if HAVE_BIGENDIAN
#define GET_TMP2(dst, p)        \
#else
#define GET_TMP2(dst,p)         \
#endif
#define ADD(dest,src,perm)                                              \
#define PUT_OP_U8_ALTIVEC(d, s, dst) d = s
#define AVG_OP_U8_ALTIVEC(d, s, dst) d = vec_avg(dst, s)
#define OP_U8_ALTIVEC                          PUT_OP_U8_ALTIVEC
#define PREFIX_no_rnd_vc1_chroma_mc8_altivec   put_no_rnd_vc1_chroma_mc8_altivec
#include "h264chroma_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_no_rnd_vc1_chroma_mc8_altivec
#define OP_U8_ALTIVEC                          AVG_OP_U8_ALTIVEC
#define PREFIX_no_rnd_vc1_chroma_mc8_altivec   avg_no_rnd_vc1_chroma_mc8_altivec
#include "h264chroma_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_no_rnd_vc1_chroma_mc8_altivec
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */

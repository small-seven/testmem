#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/h264chroma.h"
#if HAVE_ALTIVEC
#define PUT_OP_U8_ALTIVEC(d, s, dst) d = s
#define AVG_OP_U8_ALTIVEC(d, s, dst) d = vec_avg(dst, s)
#define OP_U8_ALTIVEC                          PUT_OP_U8_ALTIVEC
#define PREFIX_h264_chroma_mc8_altivec         put_h264_chroma_mc8_altivec
#define PREFIX_h264_chroma_mc8_num             altivec_put_h264_chroma_mc8_num
#include "h264chroma_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_h264_chroma_mc8_altivec
#undef PREFIX_h264_chroma_mc8_num
#define OP_U8_ALTIVEC                          AVG_OP_U8_ALTIVEC
#define PREFIX_h264_chroma_mc8_altivec         avg_h264_chroma_mc8_altivec
#define PREFIX_h264_chroma_mc8_num             altivec_avg_h264_chroma_mc8_num
#include "h264chroma_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_h264_chroma_mc8_altivec
#undef PREFIX_h264_chroma_mc8_num
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */

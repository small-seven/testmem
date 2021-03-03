#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/h264qpel.h"
#include "hpeldsp_altivec.h"
#if HAVE_ALTIVEC
#define PUT_OP_U8_ALTIVEC(d, s, dst) d = s
#define AVG_OP_U8_ALTIVEC(d, s, dst) d = vec_avg(dst, s)
#define OP_U8_ALTIVEC                          PUT_OP_U8_ALTIVEC
#define PREFIX_h264_qpel16_h_lowpass_altivec   put_h264_qpel16_h_lowpass_altivec
#define PREFIX_h264_qpel16_h_lowpass_num       altivec_put_h264_qpel16_h_lowpass_num
#define PREFIX_h264_qpel16_v_lowpass_altivec   put_h264_qpel16_v_lowpass_altivec
#define PREFIX_h264_qpel16_v_lowpass_num       altivec_put_h264_qpel16_v_lowpass_num
#define PREFIX_h264_qpel16_hv_lowpass_altivec  put_h264_qpel16_hv_lowpass_altivec
#define PREFIX_h264_qpel16_hv_lowpass_num      altivec_put_h264_qpel16_hv_lowpass_num
#include "h264qpel_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_h264_qpel16_h_lowpass_altivec
#undef PREFIX_h264_qpel16_h_lowpass_num
#undef PREFIX_h264_qpel16_v_lowpass_altivec
#undef PREFIX_h264_qpel16_v_lowpass_num
#undef PREFIX_h264_qpel16_hv_lowpass_altivec
#undef PREFIX_h264_qpel16_hv_lowpass_num
#define OP_U8_ALTIVEC                          AVG_OP_U8_ALTIVEC
#define PREFIX_h264_qpel16_h_lowpass_altivec   avg_h264_qpel16_h_lowpass_altivec
#define PREFIX_h264_qpel16_h_lowpass_num       altivec_avg_h264_qpel16_h_lowpass_num
#define PREFIX_h264_qpel16_v_lowpass_altivec   avg_h264_qpel16_v_lowpass_altivec
#define PREFIX_h264_qpel16_v_lowpass_num       altivec_avg_h264_qpel16_v_lowpass_num
#define PREFIX_h264_qpel16_hv_lowpass_altivec  avg_h264_qpel16_hv_lowpass_altivec
#define PREFIX_h264_qpel16_hv_lowpass_num      altivec_avg_h264_qpel16_hv_lowpass_num
#include "h264qpel_template.c"
#undef OP_U8_ALTIVEC
#undef PREFIX_h264_qpel16_h_lowpass_altivec
#undef PREFIX_h264_qpel16_h_lowpass_num
#undef PREFIX_h264_qpel16_v_lowpass_altivec
#undef PREFIX_h264_qpel16_v_lowpass_num
#undef PREFIX_h264_qpel16_hv_lowpass_altivec
#undef PREFIX_h264_qpel16_hv_lowpass_num
#define H264_MC(OPNAME, SIZE, CODETYPE) \
#if HAVE_BIGENDIAN
#define put_unligned_store(s, dest) {    \
#else
#define put_unligned_store(s, dest) vec_vsx_st(s, 0, dest);
#endif /* HAVE_BIGENDIAN */
#if HAVE_BIGENDIAN
#endif
#if HAVE_BIGENDIAN
#define avg_unligned_store(s, dest){            \
#else
#define avg_unligned_store(s, dest){            \
#endif /* HAVE_BIGENDIAN */
#if HAVE_BIGENDIAN
#endif
#define put_pixels16_l2_altivec(d,s1,s2,ds,s1s,h) put_pixels16_l2(d,s1,s2,ds,s1s,16,h)
#define avg_pixels16_l2_altivec(d,s1,s2,ds,s1s,h) avg_pixels16_l2(d,s1,s2,ds,s1s,16,h)
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#define dspfunc(PFX, IDX, NUM) \
#undef dspfunc
#endif /* HAVE_ALTIVEC */

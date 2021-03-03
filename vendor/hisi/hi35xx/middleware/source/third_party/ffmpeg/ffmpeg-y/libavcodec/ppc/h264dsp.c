#include "config.h"
#include <stdint.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/h264dec.h"
#include "libavcodec/h264dsp.h"
#if HAVE_ALTIVEC
#define VEC_1D_DCT(vb0,vb1,vb2,vb3,va0,va1,va2,va3)               \
#define VEC_TRANSPOSE_4(a0,a1,a2,a3,b0,b1,b2,b3) \
#if HAVE_BIGENDIAN
#define vdst_load(d)              \
#else
#define vdst_load(d) vdst = vec_vsx_ld(0, dst)
#endif
#define VEC_LOAD_U8_ADD_S16_STORE_U8(va)                      \
#define IDCT8_1D_ALTIVEC(s0, s1, s2, s3, s4, s5, s6, s7,  d0, d1, d2, d3, d4, d5, d6, d7) {\
#if HAVE_BIGENDIAN
#define GET_2PERM(ldv, stv, d)  \
#define dstv_load(d)            \
#define dest_unligned_store(d)                                 \
#else
#define GET_2PERM(ldv, stv, d) {}
#define dstv_load(d) vec_u8 dstv = vec_vsx_ld(0, d)
#define dest_unligned_store(d)\
#endif /* HAVE_BIGENDIAN */
#define ALTIVEC_STORE_SUM_CLIP(dest, idctv, perm_ldv, perm_stv, sel) { \
#if HAVE_BIGENDIAN
#define DST_LD vec_ld
#else
#define DST_LD vec_vsx_ld
#endif
#if HAVE_BIGENDIAN
#endif
#define transpose4x16(r0, r1, r2, r3) {      \
#define readAndTranspose16x6(src, src_stride, r8, r9, r10, r11, r12, r13) {\
#define h264_deblock_p0_q0(p0, p1, q0, q1, tc0masked) {                                           \
#define h264_loop_filter_luma_altivec(p2, p1, p0, q0, q1, q2, alpha, beta, tc0) {            \
#if !HAVE_BIGENDIAN
#endif
#if !HAVE_BIGENDIAN
#endif
#define H264_WEIGHT(W) \
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */

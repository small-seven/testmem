#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/ppc/util_altivec.h"
#define ASSERT_ALIGNED(ptr) av_assert2(!((uintptr_t)ptr&0x0000000F));
#if HAVE_BIGENDIAN
#define load_alignment(s, ali, pm2, pm1, pp0, pp1, pp2, pp3){\
#else
#define load_alignment(s, ali, pm2, pm1, pp0, pp1, pp2, pp3){\
#endif /* HAVE_BIGENDIAN */
#ifdef PREFIX_h264_qpel16_h_lowpass_altivec
#if HAVE_BIGENDIAN
#endif /* HAVE_BIGENDIAN */
#endif /* PREFIX_h264_qpel16_h_lowpass_altivec */
#ifdef PREFIX_h264_qpel16_v_lowpass_altivec
#if HAVE_BIGENDIAN
#endif
#endif /* PREFIX_h264_qpel16_v_lowpass_altivec */
#ifdef PREFIX_h264_qpel16_hv_lowpass_altivec
#if HAVE_BIGENDIAN
#endif /* HAVE_BIGENDIAN */
#if !HAVE_BIGENDIAN
#endif
#endif /* PREFIX_h264_qpel16_hv_lowpass_altivec */

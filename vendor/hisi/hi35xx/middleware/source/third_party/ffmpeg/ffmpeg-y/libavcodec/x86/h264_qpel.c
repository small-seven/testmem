#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/h264dec.h"
#include "libavcodec/h264qpel.h"
#include "libavcodec/pixels.h"
#include "fpel.h"
#if HAVE_X86ASM
#define ff_put_pixels8_l2_sse2  ff_put_pixels8_l2_mmxext
#define ff_avg_pixels8_l2_sse2  ff_avg_pixels8_l2_mmxext
#define ff_put_pixels16_l2_sse2 ff_put_pixels16_l2_mmxext
#define ff_avg_pixels16_l2_sse2 ff_avg_pixels16_l2_mmxext
#define ff_put_pixels16_mmxext  ff_put_pixels16_mmx
#define ff_put_pixels8_mmxext   ff_put_pixels8_mmx
#define ff_put_pixels4_mmxext   ff_put_pixels4_mmx
#define DEF_QPEL(OPNAME)\
#define QPEL_H264(OPNAME, OP, MMX)\
#if ARCH_X86_64
#define QPEL_H264_H16_XMM(OPNAME, OP, MMX)\
#else // ARCH_X86_64
#define QPEL_H264_H16_XMM(OPNAME, OP, MMX)\
#endif // ARCH_X86_64
#define QPEL_H264_H_XMM(OPNAME, OP, MMX)\
#define QPEL_H264_V_XMM(OPNAME, OP, MMX)\
#define QPEL_H264_HV_XMM(OPNAME, OP, MMX)\
#define ff_put_h264_qpel8_h_lowpass_l2_sse2  ff_put_h264_qpel8_h_lowpass_l2_mmxext
#define ff_avg_h264_qpel8_h_lowpass_l2_sse2  ff_avg_h264_qpel8_h_lowpass_l2_mmxext
#define ff_put_h264_qpel16_h_lowpass_l2_sse2 ff_put_h264_qpel16_h_lowpass_l2_mmxext
#define ff_avg_h264_qpel16_h_lowpass_l2_sse2 ff_avg_h264_qpel16_h_lowpass_l2_mmxext
#define ff_put_h264_qpel8_v_lowpass_ssse3  ff_put_h264_qpel8_v_lowpass_sse2
#define ff_avg_h264_qpel8_v_lowpass_ssse3  ff_avg_h264_qpel8_v_lowpass_sse2
#define ff_put_h264_qpel16_v_lowpass_ssse3 ff_put_h264_qpel16_v_lowpass_sse2
#define ff_avg_h264_qpel16_v_lowpass_ssse3 ff_avg_h264_qpel16_v_lowpass_sse2
#define ff_put_h264_qpel8or16_hv2_lowpass_sse2 ff_put_h264_qpel8or16_hv2_lowpass_mmxext
#define ff_avg_h264_qpel8or16_hv2_lowpass_sse2 ff_avg_h264_qpel8or16_hv2_lowpass_mmxext
#define H264_MC(OPNAME, SIZE, MMX, ALIGN) \
#define put_h264_qpel8_mc00_sse2 put_h264_qpel8_mc00_mmxext
#define avg_h264_qpel8_mc00_sse2 avg_h264_qpel8_mc00_mmxext
#define H264_MC_C(OPNAME, SIZE, MMX, ALIGN) \
#define H264_MC_H(OPNAME, SIZE, MMX, ALIGN) \
#define H264_MC_V(OPNAME, SIZE, MMX, ALIGN) \
#define H264_MC_HV(OPNAME, SIZE, MMX, ALIGN) \
#define H264_MC_4816(MMX)\
#define H264_MC_816(QPEL, XMM)\
#define LUMA_MC_OP(OP, NUM, DEPTH, TYPE, OPT) \
#define LUMA_MC_ALL(DEPTH, TYPE, OPT) \
#define LUMA_MC_816(DEPTH, TYPE, OPT) \
#define QPEL16_OPMC(OP, MC, MMX)\
#define QPEL16_OP(MC, MMX)\
#define QPEL16(MMX)\
#if ARCH_X86_32 // ARCH_X86_64 implies SSE2+
#endif
#endif /* HAVE_X86ASM */
#define SET_QPEL_FUNCS(PFX, IDX, SIZE, CPU, PREFIX)                          \
#define H264_QPEL_FUNCS(x, y, CPU)                                                            \
#define H264_QPEL_FUNCS_10(x, y, CPU)                                                               \
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#endif

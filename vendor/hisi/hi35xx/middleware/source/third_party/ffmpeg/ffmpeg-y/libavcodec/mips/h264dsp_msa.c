#include "libavutil/mips/generic_macros_msa.h"
#include "h264dsp_mips.h"
#define AVC_LPF_P0P1P2_OR_Q0Q1Q2(p3_or_q3_org_in, p0_or_q0_org_in,          \
#define AVC_LPF_P0_OR_Q0(p0_or_q0_org_in, q1_or_p1_org_in,   \
#define AVC_LPF_P1_OR_Q1(p0_or_q0_org_in, q0_or_p0_org_in,    \
#define AVC_LPF_P0Q0(q0_or_p0_org_in, p0_or_q0_org_in,          \
#define AVC_LPF_H_CHROMA_422(src, stride, tc_val, alpha, beta, res)      \
#define TRANSPOSE2x4_B_UB(in0, in1, out0, out1, out2, out3)  \
#define AVC_LPF_H_2BYTE_CHROMA_422(src, stride, tc_val, alpha, beta, res)  \

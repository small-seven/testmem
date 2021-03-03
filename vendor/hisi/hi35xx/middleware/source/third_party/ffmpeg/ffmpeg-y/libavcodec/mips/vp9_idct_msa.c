#include <string.h>
#include "libavcodec/vp9dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp9dsp_mips.h"
#define VP9_DCT_CONST_BITS   14
#define ROUND_POWER_OF_TWO(value, n)  (((value) + (1 << ((n) - 1))) >> (n))
#define VP9_DOTP_CONST_PAIR(reg0, reg1, cnst0, cnst1, out0, out1)  \
#define VP9_DOT_ADD_SUB_SRARI_PCK(in0, in1, in2, in3, in4, in5, in6, in7,  \
#define VP9_DOT_SHIFT_RIGHT_PCK_H(in0, in1, in2)          \
#define VP9_ADST8(in0, in1, in2, in3, in4, in5, in6, in7,                 \
#define VP9_MADD_SHORT(m0, m1, c0, c1, res0, res1)                        \
#define VP9_MADD_BF(inp0, inp1, inp2, inp3, cst0, cst1, cst2, cst3,       \
#define VP9_SET_COSPI_PAIR(c0_h, c1_h)   \
#define VP9_ADDBLK_ST8x4_UB(dst, dst_stride, in0, in1, in2, in3)  \
#define VP9_IDCT4x4(in0, in1, in2, in3, out0, out1, out2, out3)       \
#define VP9_IADST4x4(in0, in1, in2, in3, out0, out1, out2, out3)      \
#define TRANSPOSE4X8_SH_SH(in0, in1, in2, in3, in4, in5, in6, in7,          \
#define VP9_SET_CONST_PAIR(mask_h, idx1_h, idx2_h)     \
#define VP9_MADD(inp0, inp1, inp2, inp3, cst0, cst1, cst2, cst3,          \
#define VP9_IDCT8x8_1D(in0, in1, in2, in3, in4, in5, in6, in7,                 \
#define VP9_IADST8x8_1D(in0, in1, in2, in3, in4, in5, in6, in7,              \
#define VP9_IADST8x16_1D(r0, r1, r2, r3, r4, r5, r6, r7, r8,          \

#include "libavutil/mips/generic_macros_msa.h"
#include "libavcodec/mips/hevcdsp_mips.h"
#define HEVC_IDCT4x4_COL(in_r0, in_l0, in_r1, in_l1,          \
#define HEVC_IDCT8x8_COL(in0, in1, in2, in3, in4, in5, in6, in7, shift)  \
#define HEVC_IDCT16x16_COL(src0_r, src1_r, src2_r, src3_r,                \
#define HEVC_EVEN16_CALC(input, sum0_r, sum0_l, load_idx, store_idx)  \
#define HEVC_IDCT_LUMA4x4_COL(in_r0, in_l0, in_r1, in_l1,     \

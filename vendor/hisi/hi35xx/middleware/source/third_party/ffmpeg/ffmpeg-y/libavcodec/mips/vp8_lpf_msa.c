#include "libavcodec/vp8dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp8dsp_mips.h"
#define VP8_SIMPLE_MASK(p1, p0, q0, q1, b_limit, mask)           \
#define VP8_LPF_FILTER4_4W(p1_in_out, p0_in_out, q0_in_out, q1_in_out,  \
#define VP8_SIMPLE_FILT(p1_in, p0_in, q0_in, q1_in, mask)           \
#define VP8_MBFILTER(p2, p1, p0, q0, q1, q2, mask, hev)             \
#define LPF_MASK_HEV(p3_in, p2_in, p1_in, p0_in,                   \
#define VP8_ST6x1_UB(in0, in0_idx, in1, in1_idx, pdst, stride)  \

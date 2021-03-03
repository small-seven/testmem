#include "libavcodec/vp9dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp9dsp_mips.h"
#define VP9_LPF_FILTER4_4W(p1_in, p0_in, q0_in, q1_in, mask_in, hev_in,  \
#define VP9_FLAT4(p3_in, p2_in, p0_in, q0_in, q2_in, q3_in, flat_out)  \
#define VP9_FLAT5(p7_in, p6_in, p5_in, p4_in, p0_in, q0_in, q4_in,  \
#define VP9_FILTER8(p3_in, p2_in, p1_in, p0_in,                \
#define LPF_MASK_HEV(p3_in, p2_in, p1_in, p0_in,                   \

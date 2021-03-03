#include "libavutil/mips/generic_macros_msa.h"
#include "h264dsp_mips.h"
#define AVC_CALC_DPADD_B_6PIX_2COEFF_SH(vec0, vec1, vec2, vec3, vec4, vec5,  \
#define AVC_HORZ_FILTER_SH(in0, in1, mask0, mask1, mask2)  \
#define AVC_DOT_SH3_SH(in0, in1, in2, coeff0, coeff1, coeff2)       \
#define AVC_DOT_SW3_SW(in0, in1, in2, coeff0, coeff1, coeff2)       \

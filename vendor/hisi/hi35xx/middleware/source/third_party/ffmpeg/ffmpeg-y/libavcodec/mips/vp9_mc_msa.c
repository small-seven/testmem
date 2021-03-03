#include "libavcodec/vp9dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp9dsp_mips.h"
#define FILT_8TAP_DPADD_S_H(vec0, vec1, vec2, vec3,             \
#define HORIZ_8TAP_FILT(src0, src1, mask0, mask1, mask2, mask3,          \
#define HORIZ_8TAP_4WID_4VECS_FILT(src0, src1, src2, src3,                  \
#define HORIZ_8TAP_8WID_4VECS_FILT(src0, src1, src2, src3,                    \
#define PCKEV_XORI128_AVG_ST_UB(in0, in1, dst, pdst)  \
#define PCKEV_AVG_ST_UB(in0, in1, dst, pdst)                  \
#define PCKEV_AVG_ST8x4_UB(in0, in1, in2, in3,  dst0, dst1,   \
#define VP9_8TAP_MIPS_MSA_FUNC(SIZE, type, type_idx)                           \
#define VP9_COPY_AVG_MIPS_MSA_FUNC(SIZE)                           \
#define VP9_AVG_MIPS_MSA_FUNC(SIZE)                               \
#undef VP9_8TAP_MIPS_MSA_FUNC
#undef VP9_COPY_AVG_MIPS_MSA_FUNC
#undef VP9_AVG_MIPS_MSA_FUNC

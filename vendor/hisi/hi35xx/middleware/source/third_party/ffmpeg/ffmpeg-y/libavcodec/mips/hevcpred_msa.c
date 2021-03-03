#include "libavcodec/hevcdec.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "hevcpred_mips.h"
#define HEVC_PRED_PLANAR_16x2(src0_r, src0_l, tmp0, tmp1, vec0, vec1,          \

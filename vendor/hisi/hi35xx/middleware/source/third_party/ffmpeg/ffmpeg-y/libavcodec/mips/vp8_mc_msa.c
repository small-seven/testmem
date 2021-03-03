#include "libavcodec/vp8dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp8dsp_mips.h"
#define HORIZ_6TAP_FILT(src0, src1, mask0, mask1, mask2,                 \
#define HORIZ_6TAP_4WID_4VECS_FILT(src0, src1, src2, src3,             \
#define HORIZ_6TAP_8WID_4VECS_FILT(src0, src1, src2, src3,                    \
#define FILT_4TAP_DPADD_S_H(vec0, vec1, filt0, filt1)           \
#define HORIZ_4TAP_FILT(src0, src1, mask0, mask1, filt_h0, filt_h1)    \
#define HORIZ_4TAP_4WID_4VECS_FILT(src0, src1, src2, src3,             \
#define HORIZ_4TAP_8WID_4VECS_FILT(src0, src1, src2, src3,                    \

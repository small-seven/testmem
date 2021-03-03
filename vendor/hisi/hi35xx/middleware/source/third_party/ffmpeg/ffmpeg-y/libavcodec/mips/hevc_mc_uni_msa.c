#include "libavutil/mips/generic_macros_msa.h"
#include "libavcodec/mips/hevcdsp_mips.h"
#include "libavcodec/mips/hevc_macros_msa.h"
#define HORIZ_8TAP_4WID_4VECS_FILT(src0, src1, src2, src3,                  \
#define HORIZ_8TAP_8WID_4VECS_FILT(src0, src1, src2, src3,                    \
#define HORIZ_4TAP_4WID_4VECS_FILT(src0, src1, src2, src3,             \
#define HORIZ_4TAP_8WID_4VECS_FILT(src0, src1, src2, src3,                    \
#define UNI_MC_COPY(WIDTH)                                                 \
#undef UNI_MC_COPY
#define UNI_MC(PEL, DIR, WIDTH, TAP, DIR1, FILT_DIR)                           \
#undef UNI_MC
#define UNI_MC_HV(PEL, WIDTH, TAP)                                         \
#undef UNI_MC_HV

#include "libavutil/mips/generic_macros_msa.h"
#include "libavcodec/mips/hevcdsp_mips.h"
#include "libavcodec/mips/hevc_macros_msa.h"
#define HEVC_BI_RND_CLIP2(in0, in1, vec0, vec1, rnd_val, out0, out1)  \
#define HEVC_BI_RND_CLIP4(in0, in1, in2, in3,                      \
#define HEVC_BI_RND_CLIP2_MAX_SATU(in0, in1, vec0, vec1, rnd_val,  \
#define HEVC_BI_RND_CLIP4_MAX_SATU(in0, in1, in2, in3, vec0, vec1, vec2,    \
#define BI_MC_COPY(WIDTH)                                                 \
#undef BI_MC_COPY
#define BI_MC(PEL, DIR, WIDTH, TAP, DIR1, FILT_DIR)                          \
#undef BI_MC
#define BI_MC_HV(PEL, WIDTH, TAP)                                         \
#undef BI_MC_HV

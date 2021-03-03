#include "libavutil/mips/generic_macros_msa.h"
#include "libavcodec/mips/hevcdsp_mips.h"
#include "libavcodec/mips/hevc_macros_msa.h"
#define HEVC_BIW_RND_CLIP2(in0, in1, vec0, vec1, wgt, rnd, offset,  \
#define HEVC_BIW_RND_CLIP4(in0, in1, in2, in3, vec0, vec1, vec2, vec3,       \
#define HEVC_BIW_RND_CLIP2_MAX_SATU(in0, in1, vec0, vec1, wgt, rnd,  \
#define HEVC_BIW_RND_CLIP4_MAX_SATU(in0, in1, in2, in3, vec0, vec1, vec2,  \
#define BI_W_MC_COPY(WIDTH)                                                  \
#undef BI_W_MC_COPY
#define BI_W_MC(PEL, DIR, WIDTH, TAP, DIR1, FILT_DIR)                         \
#undef BI_W_MC
#define BI_W_MC_HV(PEL, WIDTH, TAP)                                         \
#undef BI_W_MC_HV

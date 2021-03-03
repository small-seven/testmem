#include "libavutil/mips/generic_macros_msa.h"
#include "libavcodec/mips/hevcdsp_mips.h"
#include "libavcodec/mips/hevc_macros_msa.h"
#define HEVC_UNIW_RND_CLIP2_MAX_SATU_H(in0_h, in1_h, wgt_w, offset_h, rnd_w,  \
#define HEVC_UNIW_RND_CLIP4_MAX_SATU_H(in0_h, in1_h, in2_h, in3_h, wgt_w,  \
#define UNIWGT_MC_COPY(WIDTH)                                                \
#undef UNIWGT_MC_COPY
#define UNI_W_MC(PEL, DIR, WIDTH, TAP, DIR1, FILT_DIR)                        \
#undef UNI_W_MC
#define UNI_W_MC_HV(PEL, WIDTH, TAP)                                          \
#undef UNI_W_MC_HV

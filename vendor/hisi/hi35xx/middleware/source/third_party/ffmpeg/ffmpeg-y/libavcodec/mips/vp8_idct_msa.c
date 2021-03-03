#include <string.h>
#include "libavcodec/vp8dsp.h"
#include "libavutil/mips/generic_macros_msa.h"
#include "vp8dsp_mips.h"
#define VP8_IDCT_1D_W(in0, in1, in2, in3, out0, out1, out2, out3)    \

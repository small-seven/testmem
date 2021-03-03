#include "h264dsp_mips.h"
#include "hpeldsp_mips.h"
#include "libavcodec/bit_depth_template.c"
#include "libavutil/mips/mmiutils.h"
#define op2_avg(a, b)  a = (((a)+CLIP(((b) + 512)>>10)+1)>>1)
#define op2_put(a, b)  a = CLIP(((b) + 512)>>10)
#undef op2_avg
#undef op2_put

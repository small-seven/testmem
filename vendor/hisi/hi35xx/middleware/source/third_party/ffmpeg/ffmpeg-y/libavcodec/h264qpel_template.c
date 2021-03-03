#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "bit_depth_template.c"
#include "hpel_template.c"
#include "pel_template.c"
#define H264_LOWPASS(OPNAME, OP, OP2) \
#define H264_MC(OPNAME, SIZE) \
#define op_avg(a, b)  a = (((a)+CLIP(((b) + 16)>>5)+1)>>1)
#define op_put(a, b)  a = CLIP(((b) + 16)>>5)
#define op2_avg(a, b)  a = (((a)+CLIP(((b) + 512)>>10)+1)>>1)
#define op2_put(a, b)  a = CLIP(((b) + 512)>>10)
#undef op_avg
#undef op_put
#undef op2_avg
#undef op2_put

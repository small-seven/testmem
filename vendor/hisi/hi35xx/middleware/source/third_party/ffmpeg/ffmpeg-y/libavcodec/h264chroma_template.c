#include <stddef.h>
#include "libavutil/avassert.h"
#include "bit_depth_template.c"
#define H264_CHROMA_MC(OPNAME, OP)\
#define op_avg(a, b) a = (((a)+(((b) + 32)>>6)+1)>>1)
#define op_put(a, b) a = (((b) + 32)>>6)
#undef op_avg
#undef op_put

#include "libavutil/intreadwrite.h"
#include "pixels.h"
#include "bit_depth_template.c"
#define DEF_HPEL(OPNAME, OP)                                            \
#define op_avg(a, b) a = rnd_avg_pixel4(a, b)
#define op_put(a, b) a = b
#undef op_avg
#undef op_put

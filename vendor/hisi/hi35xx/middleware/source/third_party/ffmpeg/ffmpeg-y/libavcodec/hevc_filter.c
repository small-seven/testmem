#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "cabac_functions.h"
#include "hevcdec.h"
#include "bit_depth_template.c"
#define LUMA 0
#define CB 1
#define CR 2
#define CTB(tab, x, y) ((tab)[(y) * s->ps.sps->ctb_width + (x)])
#define TC_CALC(qp, bs)                                                 \
#undef LUMA
#undef CB
#undef CR

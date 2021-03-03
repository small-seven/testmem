#include "libavutil/attributes.h"
#include "h264qpel.h"
#define pixeltmp int16_t
#define BIT_DEPTH 8
#include "h264qpel_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "h264qpel_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "h264qpel_template.c"
#undef BIT_DEPTH
#undef pixeltmp
#define pixeltmp int32_t
#define BIT_DEPTH 12
#include "h264qpel_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 14
#include "h264qpel_template.c"
#undef BIT_DEPTH
#undef FUNCC
#define FUNCC(f, depth) f ## _ ## depth ## _c
#define dspfunc2(PFX, IDX, NUM, depth)                                  \
#define SET_QPEL(depth)                         \

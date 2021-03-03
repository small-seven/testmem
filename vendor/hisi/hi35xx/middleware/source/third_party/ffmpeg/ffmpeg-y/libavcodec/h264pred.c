#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "h264pred.h"
#define BIT_DEPTH 8
#include "h264pred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "h264pred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "h264pred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "h264pred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 14
#include "h264pred_template.c"
#undef BIT_DEPTH
#undef FUNC
#undef FUNCC
#define FUNC(a, depth) a ## _ ## depth
#define FUNCC(a, depth) a ## _ ## depth ## _c
#define FUNCD(a) a ## _c
#define H264_PRED(depth) \

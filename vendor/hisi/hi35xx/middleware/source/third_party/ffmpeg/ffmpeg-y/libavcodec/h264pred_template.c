#include "libavutil/intreadwrite.h"
#include "mathops.h"
#include "bit_depth_template.c"
#define LOAD_TOP_RIGHT_EDGE\
#define LOAD_DOWN_LEFT_EDGE\
#define LOAD_LEFT_EDGE\
#define LOAD_TOP_EDGE\
#define PREDICT_16x16_DC(v)\
#define PRED16x16_X(n, v) \
#define PRED8x8_X(n, v)\
#define SRC(x,y) src[(x)+(y)*stride]
#define PL(y) \
#define PREDICT_8x8_LOAD_LEFT \
#define PT(x) \
#define PREDICT_8x8_LOAD_TOP \
#define PTR(x) \
#define PREDICT_8x8_LOAD_TOPRIGHT \
#define PREDICT_8x8_LOAD_TOPLEFT \
#define PREDICT_8x8_DC(v) \
#define ROW(y) a = PIXEL_SPLAT_X4(l##y); \
#undef ROW
#undef PREDICT_8x8_LOAD_LEFT
#undef PREDICT_8x8_LOAD_TOP
#undef PREDICT_8x8_LOAD_TOPLEFT
#undef PREDICT_8x8_LOAD_TOPRIGHT
#undef PREDICT_8x8_DC
#undef PTR
#undef PT
#undef PL
#undef SRC

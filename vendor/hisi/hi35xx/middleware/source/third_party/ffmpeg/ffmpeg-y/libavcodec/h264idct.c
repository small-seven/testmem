#include "h264idct.h"
#define BIT_DEPTH 8
#include "h264idct_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "h264idct_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "h264idct_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "h264idct_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 14
#include "h264idct_template.c"
#undef BIT_DEPTH

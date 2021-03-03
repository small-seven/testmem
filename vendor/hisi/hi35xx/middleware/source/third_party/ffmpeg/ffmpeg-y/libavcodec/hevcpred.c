#include "hevcdec.h"
#include "hevcpred.h"
#define BIT_DEPTH 8
#include "hevcpred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "hevcpred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "hevcpred_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "hevcpred_template.c"
#undef BIT_DEPTH
#undef FUNC
#define FUNC(a, depth) a ## _ ## depth
#define HEVC_PRED(depth)                                \

#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "videodsp.h"
#define BIT_DEPTH 8
#include "videodsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 16
#include "videodsp_template.c"
#undef BIT_DEPTH

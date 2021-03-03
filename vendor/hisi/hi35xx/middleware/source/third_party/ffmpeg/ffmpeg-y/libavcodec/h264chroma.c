#include "config.h"
#include "libavutil/attributes.h"
#include "h264chroma.h"
#define BIT_DEPTH 8
#include "h264chroma_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 16
#include "h264chroma_template.c"
#undef BIT_DEPTH
#define SET_CHROMA(depth)                                                   \

#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "h264dsp.h"
#include "h264idct.h"
#include "startcode.h"
#include "libavutil/common.h"
#define BIT_DEPTH 8
#include "h264dsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 9
#include "h264dsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "h264dsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "h264dsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 14
#include "h264dsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 8
#include "h264addpx_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 16
#include "h264addpx_template.c"
#undef BIT_DEPTH
#undef FUNC
#define FUNC(a, depth) a ## _ ## depth ## _c
#define ADDPX_DSP(depth) \
#define H264_DSP(depth) \

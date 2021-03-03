#include <string.h>
#include "checkasm.h"
#include "libavfilter/blend.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define WIDTH 256
#define HEIGHT 256
#define BUF_UNITS 3
#define SIZE_PER_UNIT (WIDTH * HEIGHT)
#define BUF_SIZE (BUF_UNITS * SIZE_PER_UNIT)
#define randomize_buffers()                   \
#define check_blend_func(depth)                                                            \
#define check_and_report(name, val, depth)        \

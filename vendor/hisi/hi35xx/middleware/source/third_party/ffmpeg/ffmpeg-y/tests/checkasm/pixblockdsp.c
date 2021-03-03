#include <string.h>
#include "checkasm.h"
#include "libavcodec/pixblockdsp.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define BUF_UNITS 8
#define BUF_SIZE (BUF_UNITS * 128 + 8 * BUF_UNITS)
#define randomize_buffers()                 \
#define check_get_pixels(type)                                                             \
#define check_diff_pixels(type)                                                            \

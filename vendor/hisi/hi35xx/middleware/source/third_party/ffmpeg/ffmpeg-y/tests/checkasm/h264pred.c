#include <string.h>
#include "checkasm.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/h264pred.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define SIZEOF_PIXEL ((bit_depth + 7) / 8)
#define BUF_SIZE (3 * 16 * 17)
#define check_pred_func(func, name, mode_name)                                    \
#define randomize_buffers()                        \
#define src0 (buf0 + 4 * 16) /* Offset to allow room for top and left */
#define src1 (buf1 + 4 * 16)

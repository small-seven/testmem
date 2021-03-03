#include <string.h>
#include "checkasm.h"
#include "libavcodec/h264qpel.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define SIZEOF_PIXEL ((bit_depth + 7) / 8)
#define BUF_SIZE (2 * 16 * (16 + 3 + 4))
#define randomize_buffers()                        \
#define src0 (buf0 + 3 * 2 * 16) /* h264qpel functions read data from negative src pointer offsets */
#define src1 (buf1 + 3 * 2 * 16)

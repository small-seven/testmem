#include <string.h>
#include "checkasm.h"
#include "libavcodec/bswapdsp.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define BUF_SIZE 512
#define randomize_buffers()                 \
#define check_bswap(type)                                                                  \

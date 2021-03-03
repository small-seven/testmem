#include <string.h>
#include "checkasm.h"
#include "libavcodec/v210enc.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define BUF_SIZE 512
#define randomize_buffers(mask)                        \
#define check_pack_line(type, mask)                                                \

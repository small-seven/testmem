#include <string.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavcodec/lossless_videodsp.h"
#include "checkasm.h"
#define randomize_buffers(buf, size)     \
#define init_buffer(a0, a1, type, width)\

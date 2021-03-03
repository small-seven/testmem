#include <string.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavcodec/huffyuvdsp.h"
#include "checkasm.h"
#define randomize_buffers(buf, size)     \

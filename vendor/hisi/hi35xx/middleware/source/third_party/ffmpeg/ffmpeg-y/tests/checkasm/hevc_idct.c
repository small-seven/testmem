#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavcodec/hevcdsp.h"
#include "checkasm.h"
#define randomize_buffers(buf, size)            \

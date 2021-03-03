#include <string.h>
#include "checkasm.h"
#include "libavfilter/hflip.h"
#include "libavutil/intreadwrite.h"
#define WIDTH 256
#define WIDTH_PADDED 256 + 32
#define randomize_buffers(buf, size)      \

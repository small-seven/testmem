#include <string.h>
#include "checkasm.h"
#include "libavcodec/flacdsp.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define BUF_SIZE 256
#define MAX_CHANNELS 8
#define randomize_buffers()                                 \

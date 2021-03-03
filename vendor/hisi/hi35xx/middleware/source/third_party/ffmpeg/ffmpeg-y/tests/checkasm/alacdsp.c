#include <string.h>
#include "checkasm.h"
#include "libavcodec/alacdsp.h"
#include "libavcodec/mathops.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#define BUF_SIZE 256
#define MAX_CHANNELS 2
#define randomize_buffers()                           \
#undef randomize_buffers
#define randomize_buffers()                           \

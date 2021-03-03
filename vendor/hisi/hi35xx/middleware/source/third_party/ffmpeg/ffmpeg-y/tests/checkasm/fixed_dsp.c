#include "checkasm.h"
#include "libavutil/common.h"
#include "libavutil/fixed_dsp.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#define BUF_SIZE 256
#define randomize_buffers()                   \

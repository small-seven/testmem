#include <string.h>
#include "checkasm.h"
#include "libavfilter/colorspacedsp.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define W 64
#define H 64
#define randomize_buffers()                     \
#undef randomize_buffers
#define randomize_buffers()                     \

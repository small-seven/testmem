#include "config.h"
#include <float.h>
#include <stdint.h>
#include "libavfilter/af_afir.h"
#include "libavutil/internal.h"
#include "checkasm.h"
#define LEN 256
#define randomize_buffer(buf)                 \

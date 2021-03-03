#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libavcodec/audiodsp.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "checkasm.h"
#define MAX_SIZE (32 * 128)
#define randomize_float(buf, len)                               \
#define randomize_int(buf, len, size, bits)                         \

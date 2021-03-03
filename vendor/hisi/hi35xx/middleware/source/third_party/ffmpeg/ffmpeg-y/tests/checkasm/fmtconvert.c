#include <math.h>
#include <stdint.h>
#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/common.h"
#include "libavcodec/fmtconvert.h"
#include "checkasm.h"
#define BUF_SIZE 1024
#define randomize_input(len)                                    \

#include <stdint.h>
#include "config.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264_ps.h"
#include "qpeldsp.h"
#include "thread.h"
#define XCHG(a, b, xchg)                        \
#define BITS   8
#define SIMPLE 1
#include "h264_mb_template.c"
#undef  BITS
#define BITS   16
#include "h264_mb_template.c"
#undef  SIMPLE
#define SIMPLE 0
#include "h264_mb_template.c"

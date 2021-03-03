#include "avformat.h"
#include "internal.h"
#include "libavutil/log.h"
#include "libavutil/intreadwrite.h"
typedef struct SCCContext {
    int prev_h, prev_m, prev_s, prev_f;
    int inside;
    int n;
} SCCContext;

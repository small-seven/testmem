#include "avformat.h"
#include "internal.h"
#include "libavutil/intreadwrite.h"
typedef struct IVFEncContext {
    unsigned frame_cnt;
    uint64_t last_pts, sum_delta_pts;
} IVFEncContext;

#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "internal.h"
typedef struct VFRDETContext {
    const AVClass *class;

    int64_t prev_pts;
    int64_t delta;
    int64_t min_delta;
    int64_t max_delta;

    uint64_t vfr;
    uint64_t cfr;
} VFRDETContext;

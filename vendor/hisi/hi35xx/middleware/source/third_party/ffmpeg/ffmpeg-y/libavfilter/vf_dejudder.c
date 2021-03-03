#include "libavutil/opt.h"
#include "libavutil/mathematics.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct DejudderContext {
    const AVClass *class;
    int64_t *ringbuff;
    int i1, i2, i3, i4;
    int64_t new_pts;
    int start_count;

    /* options */
    int cycle;
} DejudderContext;
#define OFFSET(x) offsetof(DejudderContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM

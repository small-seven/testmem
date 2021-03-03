#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "avfilter.h"
#include "internal.h"
#include <float.h>
typedef struct RealtimeContext {
    const AVClass *class;
    int64_t delta;
    int64_t limit;
    double speed;
    unsigned inited;
} RealtimeContext;
#define OFFSET(x) offsetof(RealtimeContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_REALTIME_FILTER
#define realtime_options options
#endif /* CONFIG_REALTIME_FILTER */
#if CONFIG_AREALTIME_FILTER
#define arealtime_options options
#endif /* CONFIG_AREALTIME_FILTER */

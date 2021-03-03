#include "libavutil/pixfmt.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct SetParamsContext {
    const AVClass *class;
    int field_mode;
    int color_range;
    int color_primaries;
    int color_trc;
    int colorspace;
} SetParamsContext;
#define OFFSET(x) offsetof(SetParamsContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_SETRANGE_FILTER
#endif /* CONFIG_SETRANGE_FILTER */
#if CONFIG_SETFIELD_FILTER
#endif /* CONFIG_SETFIELD_FILTER */

#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
typedef struct CueContext {
    const AVClass *class;
    int64_t first_pts;
    int64_t cue;
    int64_t preroll;
    int64_t buffer;
    int status;
} CueContext;
#define OFFSET(x) offsetof(CueContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_CUE_FILTER
#define cue_options options
#endif /* CONFIG_CUE_FILTER */
#if CONFIG_ACUE_FILTER
#define acue_options options
#endif /* CONFIG_ACUE_FILTER */

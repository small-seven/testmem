#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct NullContext {
    const AVClass *class;
    int frame_step;
} FrameStepContext;
#define OFFSET(x) offsetof(FrameStepContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "libpostproc/postprocess.h"
typedef struct PPFilterContext {
    const AVClass *class;
    char *subfilters;
    int mode_id;
    pp_mode *modes[PP_QUALITY_MAX + 1];
    void *pp_ctx;
} PPFilterContext;
#define OFFSET(x) offsetof(PPFilterContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

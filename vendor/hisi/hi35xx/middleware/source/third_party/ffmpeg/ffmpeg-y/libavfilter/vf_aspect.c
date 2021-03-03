#include <float.h>
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct AspectContext {
    const AVClass *class;
    AVRational dar;
    AVRational sar;
    int max;
    char *ratio_expr;
} AspectContext;
#define OFFSET(x) offsetof(AspectContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_SETDAR_FILTER
#endif /* CONFIG_SETDAR_FILTER */
#if CONFIG_SETSAR_FILTER
#endif /* CONFIG_SETSAR_FILTER */

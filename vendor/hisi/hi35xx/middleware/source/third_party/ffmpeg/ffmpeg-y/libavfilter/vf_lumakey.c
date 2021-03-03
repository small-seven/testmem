#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct LumakeyContext {
    const AVClass *class;

    int threshold;
    int tolerance;
    int softness;

    int white;
    int black;
    int max;

    int (*do_lumakey_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} LumakeyContext;
#define OFFSET(x) offsetof(LumakeyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ColorkeyContext {
    const AVClass *class;

    /* color offsets rgba */
    int co[4];

    uint8_t colorkey_rgba[4];
    float similarity;
    float blend;

    int (*do_slice)(AVFilterContext *ctx, void *arg,
                    int jobnr, int nb_jobs);
} ColorkeyContext;
#define OFFSET(x) offsetof(ColorkeyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_COLORKEY_FILTER
#endif /* CONFIG_COLORKEY_FILTER */
#if CONFIG_COLORHOLD_FILTER
#endif /* CONFIG_COLORHOLD_FILTER */

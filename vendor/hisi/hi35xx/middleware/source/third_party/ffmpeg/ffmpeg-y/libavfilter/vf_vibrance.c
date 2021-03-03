#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct VibranceContext {
    const AVClass *class;

    float intensity;
    float balance[3];
    float lcoeffs[3];
    int alternate;

    int depth;

    int (*do_slice)(AVFilterContext *s, void *arg,
                    int jobnr, int nb_jobs);
} VibranceContext;
#define OFFSET(x) offsetof(VibranceContext, x)
#define VF AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct LagfunContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    float decay;
    int planes;

    int depth;
    int nb_planes;
    int linesize[4];
    int height[4];

    AVFrame *old;

    int (*lagfun)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} LagfunContext;
typedef struct ThreadData {
    AVFrame *in, *out, *old;
} ThreadData;
#define OFFSET(x) offsetof(LagfunContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

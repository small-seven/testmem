#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct MaskFunContext {
    const AVClass *class;

    int low, high;
    int planes;
    int fill;
    int sum;

    int linesize[4];
    int width[4], height[4];
    int nb_planes;
    int depth;
    int max;
    uint64_t max_sum;

    AVFrame *empty;
    int (*getsum)(AVFilterContext *ctx, AVFrame *out);
    int (*maskfun)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} MaskFunContext;
#define OFFSET(x) offsetof(MaskFunContext, x)
#define VF AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define GETSUM(name, type, div)                              \
#define MASKFUN(name, type, div)                             \

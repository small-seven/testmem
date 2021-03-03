#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "framesync.h"
#define OFFSET(x) offsetof(MaskedClampContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *b, *o, *m, *d;
} ThreadData;
typedef struct MaskedClampContext {
    const AVClass *class;

    int planes;
    int undershoot;
    int overshoot;

    int linesize[4];
    int width[4], height[4];
    int nb_planes;
    int depth;
    FFFrameSync fs;

    int (*maskedclamp)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} MaskedClampContext;

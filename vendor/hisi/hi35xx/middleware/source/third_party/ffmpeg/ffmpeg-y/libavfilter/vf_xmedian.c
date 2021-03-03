#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/qsort.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "framesync.h"
#include "video.h"
typedef struct XMedianContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    int nb_inputs;
    int planes;

    int radius;
    int depth;
    int max;
    int nb_planes;
    int linesize[4];
    int width[4];
    int height[4];

    AVFrame **frames;
    FFFrameSync fs;

    int (*median_frames)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} XMedianContext;
typedef struct ThreadData {
    AVFrame **in, *out;
} ThreadData;
#define OFFSET(x) offsetof(XMedianContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

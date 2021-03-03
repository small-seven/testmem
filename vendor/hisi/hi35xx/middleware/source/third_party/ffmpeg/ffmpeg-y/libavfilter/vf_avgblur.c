#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct AverageBlurContext {
    const AVClass *class;

    int radius;
    int radiusV;
    int planes;

    int depth;
    int planewidth[4];
    int planeheight[4];
    float *buffer;
    int nb_planes;

    int (*filter_horizontally)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
    int (*filter_vertically)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} AverageBlurContext;
#define OFFSET(x) offsetof(AverageBlurContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    int height;
    int width;
    uint8_t *ptr;
    int linesize;
} ThreadData;
#define HORIZONTAL_FILTER(name, type)                                                         \
#define VERTICAL_FILTER(name, type)                                                           \

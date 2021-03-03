#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct DebandContext {
    const AVClass *class;

    int coupling;
    float threshold[4];
    int range;
    int blur;
    float direction;

    int nb_components;
    int planewidth[4];
    int planeheight[4];
    int shift[2];
    int thr[4];

    int *x_pos;
    int *y_pos;

    int (*deband)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} DebandContext;
#define OFFSET(x) offsetof(DebandContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;

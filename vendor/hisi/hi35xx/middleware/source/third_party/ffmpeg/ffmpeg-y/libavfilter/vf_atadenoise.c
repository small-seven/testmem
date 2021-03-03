#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#define FF_BUFQUEUE_SIZE 129
#include "bufferqueue.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define SIZE FF_BUFQUEUE_SIZE
typedef struct ATADenoiseContext {
    const AVClass *class;

    float fthra[4], fthrb[4];
    int thra[4], thrb[4];

    int planes;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];

    struct FFBufQueue q;
    void *data[4][SIZE];
    int linesize[4][SIZE];
    int size, mid;
    int available;

    int (*filter_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ATADenoiseContext;
#define OFFSET(x) offsetof(ATADenoiseContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;

#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "limiter.h"
#include "video.h"
typedef struct ThreadData {
    AVFrame *in;
    AVFrame *out;
} ThreadData;
typedef struct LimiterContext {
    const AVClass *class;
    int min;
    int max;
    int planes;
    int nb_planes;
    int linesize[4];
    int width[4];
    int height[4];

    LimiterDSPContext dsp;
} LimiterContext;
#define OFFSET(x) offsetof(LimiterContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

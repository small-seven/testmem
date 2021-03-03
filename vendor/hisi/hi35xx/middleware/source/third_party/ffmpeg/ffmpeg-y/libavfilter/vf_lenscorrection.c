#include <stdlib.h>
#include <math.h>
#include "libavutil/opt.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct LenscorrectionCtx {
    const AVClass *av_class;
    unsigned int width;
    unsigned int height;
    int hsub, vsub;
    int nb_planes;
    double cx, cy, k1, k2;
    int32_t *correction[4];
} LenscorrectionCtx;
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *in, *out;
    int w, h;
    int plane;
    int xcenter, ycenter;
    int32_t *correction;
} ThreadData;

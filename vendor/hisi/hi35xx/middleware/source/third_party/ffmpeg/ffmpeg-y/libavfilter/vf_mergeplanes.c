#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "framesync.h"
typedef struct InputParam {
    int depth[4];
    int nb_planes;
    int planewidth[4];
    int planeheight[4];
} InputParam;
typedef struct MergePlanesContext {
    const AVClass *class;
    int64_t mapping;
    const enum AVPixelFormat out_fmt;
    int nb_inputs;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];
    int map[4][2];
    const AVPixFmtDescriptor *outdesc;

    FFFrameSync fs;
} MergePlanesContext;
#define OFFSET(x) offsetof(MergePlanesContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

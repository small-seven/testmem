#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
typedef struct WeaveContext {
    const AVClass *class;
    int first_field;
    int double_weave;
    int nb_planes;
    int planeheight[4];
    int linesize[4];

    AVFrame *prev;
} WeaveContext;
#define OFFSET(x) offsetof(WeaveContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define doubleweave_options weave_options

#define DEFAULT_INPUT_NAME     "transforms.trf"
#include <vid.stab/libvidstab.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "internal.h"
#include "vidstabutils.h"
typedef struct TransformContext {
    const AVClass *class;

    VSTransformData td;
    VSTransformConfig conf;

    VSTransformations trans;    // transformations
    char *input;                // name of transform file
    int tripod;
    int debug;
} TransformContext;
#define OFFSET(x) offsetof(TransformContext, x)
#define OFFSETC(x) (offsetof(TransformContext, conf)+offsetof(VSTransformConfig, x))
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

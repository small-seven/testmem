#define DEFAULT_RESULT_NAME     "transforms.trf"
#include <vid.stab/libvidstab.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "internal.h"
#include "vidstabutils.h"
typedef struct StabData {
    const AVClass *class;

    VSMotionDetect md;
    VSMotionDetectConfig conf;

    char *result;
    FILE *f;
} StabData;
#define OFFSET(x) offsetof(StabData, x)
#define OFFSETC(x) (offsetof(StabData, conf)+offsetof(VSMotionDetectConfig, x))
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

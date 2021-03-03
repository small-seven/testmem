#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
#include "threshold.h"
#define OFFSET(x) offsetof(ThresholdContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    AVFrame *in;
    AVFrame *threshold;
    AVFrame *min;
    AVFrame *max;
    AVFrame *out;
} ThreadData;

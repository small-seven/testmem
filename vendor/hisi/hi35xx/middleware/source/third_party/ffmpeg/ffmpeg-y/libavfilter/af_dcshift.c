#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct DCShiftContext {
    const AVClass *class;
    double dcshift;
    double limiterthreshold;
    double limitergain;
} DCShiftContext;
#define OFFSET(x) offsetof(DCShiftContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

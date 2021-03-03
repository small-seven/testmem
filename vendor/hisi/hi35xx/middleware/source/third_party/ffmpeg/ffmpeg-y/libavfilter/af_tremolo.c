#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
typedef struct TremoloContext {
    const AVClass *class;
    double freq;
    double depth;
    double *table;
    int index;
} TremoloContext;
#define OFFSET(x) offsetof(TremoloContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

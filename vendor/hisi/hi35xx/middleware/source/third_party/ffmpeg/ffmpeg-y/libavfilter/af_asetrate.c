#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ASetRateContext {
    const AVClass *class;
    int sample_rate;
    int rescale_pts;
} ASetRateContext;
#define CONTEXT ASetRateContext
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OPT_GENERIC(name, field, def, min, max, descr, type, deffield, ...) \
#define OPT_INT(name, field, def, min, max, descr, ...) \

#include "libavutil/channel_layout.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct CrossfeedContext {
    const AVClass *class;

    double range;
    double strength;
    double level_in;
    double level_out;

    double a0, a1, a2;
    double b0, b1, b2;

    double i1, i2;
    double o1, o2;
} CrossfeedContext;
#define OFFSET(x) offsetof(CrossfeedContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

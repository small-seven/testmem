#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct DeesserChannel {
    double s1, s2, s3;
    double m1, m2;
    double ratioA, ratioB;
    double iirSampleA, iirSampleB;
    int flip;
} DeesserChannel;
typedef struct DeesserContext {
    const AVClass *class;

    double intensity;
    double max;
    double frequency;
    int    mode;

    DeesserChannel *chan;
} DeesserContext;
#define OFFSET(x) offsetof(DeesserContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct StereoWidenContext {
    const AVClass *class;

    float delay;
    float feedback;
    float crossfeed;
    float drymix;

    float *buffer;
    float *cur;
    int length;
} StereoWidenContext;
#define OFFSET(x) offsetof(StereoWidenContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

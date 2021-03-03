#include <inttypes.h>
#include <stdio.h>
#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ANullContext {
    const AVClass *class;
    char   *channel_layout_str;
    uint64_t channel_layout;
    char   *sample_rate_str;
    int     sample_rate;
    int nb_samples;             ///< number of samples per requested frame
    int64_t pts;
} ANullContext;
#define OFFSET(x) offsetof(ANullContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "libavutil/lfg.h"
#include "libavutil/random_seed.h"
typedef struct ANoiseSrcContext {
    const AVClass *class;
    int sample_rate;
    double amplitude;
    int64_t duration;
    int64_t color;
    int64_t seed;
    int nb_samples;

    int64_t pts;
    int infinite;
    double (*filter)(double white, double *buf);
    double buf[7];
    AVLFG c;
} ANoiseSrcContext;
#define OFFSET(x) offsetof(ANoiseSrcContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "window_func.h"
typedef struct HilbertContext {
    const AVClass *class;

    int sample_rate;
    int nb_taps;
    int nb_samples;
    int win_func;

    float *taps;
    int64_t pts;
} HilbertContext;
#define OFFSET(x) offsetof(HilbertContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

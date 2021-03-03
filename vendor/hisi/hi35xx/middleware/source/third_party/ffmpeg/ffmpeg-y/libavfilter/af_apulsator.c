#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
typedef struct SimpleLFO {
    double phase;
    double freq;
    double offset;
    double amount;
    double pwidth;
    int mode;
    int srate;
} SimpleLFO;
typedef struct AudioPulsatorContext {
    const AVClass *class;
    int mode;
    double level_in;
    double level_out;
    double amount;
    double offset_l;
    double offset_r;
    double pwidth;
    double bpm;
    double hertz;
    int ms;
    int timing;

    SimpleLFO lfoL, lfoR;
} AudioPulsatorContext;
#define OFFSET(x) offsetof(AudioPulsatorContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
typedef struct LFOContext {
    double freq;
    double offset;
    int srate;
    double amount;
    double pwidth;
    double phase;
} LFOContext;
typedef struct SRContext {
    double target;
    double real;
    double samples;
    double last;
} SRContext;
typedef struct ACrusherContext {
    const AVClass *class;

    double level_in;
    double level_out;
    double bits;
    double mix;
    int mode;
    double dc;
    double idc;
    double aa;
    double samples;
    int is_lfo;
    double lforange;
    double lforate;

    double sqr;
    double aa1;
    double coeff;
    int    round;
    double sov;
    double smin;
    double sdiff;

    LFOContext lfo;
    SRContext *sr;
} ACrusherContext;
#define OFFSET(x) offsetof(ACrusherContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

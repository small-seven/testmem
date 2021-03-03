#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#define NBANDS 17
#define M 15
typedef struct EqParameter {
    float lower, upper, gain;
} EqParameter;
typedef struct SuperEqualizerContext {
    const AVClass *class;

    EqParameter params[NBANDS + 1];

    float gains[NBANDS + 1];

    float fact[M + 1];
    float aa;
    float iza;
    float *ires, *irest;
    float *fsamples;
    int winlen, tabsize;

    AVFrame *in, *out;
    RDFTContext *rdft, *irdft;
} SuperEqualizerContext;
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OFFSET(x) offsetof(SuperEqualizerContext, x)

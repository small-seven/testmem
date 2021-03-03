#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
typedef struct BiquadCoeffs {
    double a0, a1, a2, b1, b2;
} BiquadCoeffs;
typedef struct BiquadD2 {
    double a0, a1, a2, b1, b2, w1, w2;
} BiquadD2;
typedef struct RIAACurve {
    BiquadD2 r1;
    BiquadD2 brickw;
    int use_brickw;
} RIAACurve;
typedef struct AudioEmphasisContext {
    const AVClass *class;
    int mode, type;
    double level_in, level_out;

    RIAACurve *rc;
} AudioEmphasisContext;
#define OFFSET(x) offsetof(AudioEmphasisContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

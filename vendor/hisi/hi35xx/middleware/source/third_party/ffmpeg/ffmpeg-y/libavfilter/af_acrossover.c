#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define MAX_SPLITS 16
#define MAX_BANDS MAX_SPLITS + 1
typedef struct BiquadContext {
    double a0, a1, a2;
    double b1, b2;
    double i1, i2;
    double o1, o2;
} BiquadContext;
typedef struct CrossoverChannel {
    BiquadContext lp[MAX_BANDS][4];
    BiquadContext hp[MAX_BANDS][4];
} CrossoverChannel;
typedef struct AudioCrossoverContext {
    const AVClass *class;

    char *splits_str;
    int order;

    int filter_count;
    int nb_splits;
    float *splits;

    CrossoverChannel *xover;
} AudioCrossoverContext;
#define OFFSET(x) offsetof(AudioCrossoverContext, x)
#define AF AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

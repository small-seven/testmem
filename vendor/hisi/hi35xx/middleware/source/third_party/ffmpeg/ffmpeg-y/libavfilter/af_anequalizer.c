#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#define FILTER_ORDER 4
typedef struct FoSection {
    double a0, a1, a2, a3, a4;
    double b0, b1, b2, b3, b4;

    double num[4];
    double denum[4];
} FoSection;
typedef struct EqualizatorFilter {
    int ignore;
    int channel;
    int type;

    double freq;
    double gain;
    double width;

    FoSection section[2];
} EqualizatorFilter;
typedef struct AudioNEqualizerContext {
    const AVClass *class;
    char *args;
    char *colors;
    int draw_curves;
    int w, h;

    double mag;
    int fscale;
    int nb_filters;
    int nb_allocated;
    EqualizatorFilter *filters;
    AVFrame *video;
} AudioNEqualizerContext;
#define OFFSET(x) offsetof(AudioNEqualizerContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define V AV_OPT_FLAG_VIDEO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ChanParam {
    double attack;
    double decay;
    double volume;
} ChanParam;
typedef struct CompandSegment {
    double x, y;
    double a, b;
} CompandSegment;
typedef struct CompandContext {
    const AVClass *class;
    int nb_segments;
    char *attacks, *decays, *points;
    CompandSegment *segments;
    ChanParam *channels;
    double in_min_lin;
    double out_min_lin;
    double curve_dB;
    double gain_dB;
    double initial_volume;
    double delay;
    AVFrame *delay_frame;
    int delay_samples;
    int delay_count;
    int delay_index;
    int64_t pts;

    int (*compand)(AVFilterContext *ctx, AVFrame *frame);
} CompandContext;
#define OFFSET(x) offsetof(CompandContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define MOD(a, b) (((a) >= (b)) ? (a) - (b) : (a))
#define S(x) s->segments[2 * ((x) + 1)]
#undef S
#define S(x) s->segments[2 * (x)]
#define L(x) s->segments[i - (x)]

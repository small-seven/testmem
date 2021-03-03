#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define R 0
#define G 1
#define B 2
#define A 3
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
typedef struct ColorChannelMixerContext {
    const AVClass *class;
    double rr, rg, rb, ra;
    double gr, gg, gb, ga;
    double br, bg, bb, ba;
    double ar, ag, ab, aa;

    int *lut[4][4];

    int *buffer;

    uint8_t rgba_map[4];

    int (*filter_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ColorChannelMixerContext;
#define OFFSET(x) offsetof(ColorChannelMixerContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

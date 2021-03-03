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
typedef struct Range {
    double shadows;
    double midtones;
    double highlights;
} Range;
typedef struct ColorBalanceContext {
    const AVClass *class;
    Range cyan_red;
    Range magenta_green;
    Range yellow_blue;

    uint16_t lut[3][65536];

    uint8_t rgba_map[4];
    int step;

    int (*apply_lut)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ColorBalanceContext;
#define OFFSET(x) offsetof(ColorBalanceContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

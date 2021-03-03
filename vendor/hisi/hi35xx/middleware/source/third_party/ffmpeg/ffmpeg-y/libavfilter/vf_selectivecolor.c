#include "libavutil/avassert.h"
#include "libavutil/file.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/mathops.h" // for mid_pred(), which is a macro so no link dependency
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define R 0
#define G 1
#define B 2
#define A 3
typedef int (*get_range_scale_func)(int r, int g, int b, int min_val, int max_val);

struct process_range {
    int range_id;
    uint32_t mask;
    get_range_scale_func get_scale;
};
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
typedef struct SelectiveColorContext {
    const AVClass *class;
    int correction_method;
    char *opt_cmyk_adjust[NB_RANGES];
    float cmyk_adjust[NB_RANGES][4];
    struct process_range process_ranges[NB_RANGES]; // color ranges to process
    int nb_process_ranges;
    char *psfile;
    uint8_t rgba_map[4];
    int is_16bit;
    int step;
} SelectiveColorContext;
#define OFFSET(x) offsetof(SelectiveColorContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define RANGE_OPTION(color_name, range) \
#define DECLARE_RANGE_SCALE_FUNCS(nbits)                                                    \
#define READ16(dst) do {                \
#define DECLARE_SELECTIVE_COLOR_FUNC(nbits)                                                             \
#define DEF_SELECTIVE_COLOR_FUNC(name, direct, correction_method, nbits)                                \
#define DEF_SELECTIVE_COLOR_FUNCS(nbits)                                                                \
typedef int (*selective_color_func_type)(AVFilterContext *ctx, void *td, int jobnr, int nb_jobs);

static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    int direct;
    AVFrame *out;
    ThreadData td;
    const SelectiveColorContext *s = ctx->priv;
    static const selective_color_func_type funcs[2][2][2] = {
        {
            {selective_color_indirect_absolute_8, selective_color_indirect_relative_8},

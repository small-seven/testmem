#include "libavutil/avassert.h"
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define SUB_PIXEL_BITS  8
#define SUB_PIXELS      (1 << SUB_PIXEL_BITS)
#define COEFF_BITS      11
#define LINEAR 0
#define CUBIC  1
typedef struct PerspectiveContext {
    const AVClass *class;
    char *expr_str[4][2];
    double ref[4][2];
    int32_t (*pv)[2];
    int32_t coeff[SUB_PIXELS][4];
    int interpolation;
    int linesize[4];
    int height[4];
    int hsub, vsub;
    int nb_planes;
    int sense;
    int eval_mode;

    int (*perspective)(AVFilterContext *ctx,
                       void *arg, int job, int nb_jobs);
} PerspectiveContext;
#define OFFSET(x) offsetof(PerspectiveContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    uint8_t *dst;
    int dst_linesize;
    uint8_t *src;
    int src_linesize;
    int w, h;
    int hsub, vsub;
} ThreadData;

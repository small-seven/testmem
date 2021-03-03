#include <float.h>  /* DBL_MAX */
#include "libavutil/opt.h"
#include "libavutil/eval.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct VignetteContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    int backward;
    int eval_mode;                      ///< EvalMode
#define DEF_EXPR_FIELDS(name) AVExpr *name##_pexpr; char *name##_expr; double name
    DEF_EXPR_FIELDS(angle);
    DEF_EXPR_FIELDS(x0);
    DEF_EXPR_FIELDS(y0);
    double var_values[VAR_NB];
    float *fmap;
    int fmap_linesize;
    double dmax;
    float xscale, yscale;
    uint32_t dither;
    int do_dither;
    AVRational aspect;
    AVRational scale;
} VignetteContext;
#define OFFSET(x) offsetof(VignetteContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define PARSE_EXPR(name) do {                                               \
#define TS2D(ts)     ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts))
#define TS2T(ts, tb) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts) * av_q2d(tb))

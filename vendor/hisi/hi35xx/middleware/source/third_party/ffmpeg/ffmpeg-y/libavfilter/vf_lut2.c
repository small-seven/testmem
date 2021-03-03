#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "framesync.h"
typedef struct LUT2Context {
    const AVClass *class;
    FFFrameSync fs;

    int odepth;
    char   *comp_expr_str[4];

    AVExpr *comp_expr[4];
    double var_values[VAR_VARS_NB];
    uint16_t *lut[4];  ///< lookup table for each component
    int width[4], height[4];
    int widthx[4], heightx[4];
    int widthy[4], heighty[4];
    int nb_planesx;
    int nb_planesy;
    int nb_planes;
    int depth, depthx, depthy;
    int tlut2;
    AVFrame *prev_frame;        /* only used with tlut2 */

    int (*lut2)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} LUT2Context;
typedef struct ThreadData {
    AVFrame *out, *srcx, *srcy;
} ThreadData;
#define OFFSET(x) offsetof(LUT2Context, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define BIT8_FMTS \
#define BIT9_FMTS \
#define BIT10_FMTS \
#define BIT12_FMTS \
#define BIT14_FMTS \
#define BIT16_FMTS \
#define DEFINE_LUT2(zname, xname, yname, ztype, xtype, ytype, zdiv, xdiv, ydiv)  \
#define lut2_options options
#if CONFIG_TLUT2_FILTER
#endif

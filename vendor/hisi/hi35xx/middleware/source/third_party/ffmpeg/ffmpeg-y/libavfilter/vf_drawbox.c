#include "libavutil/colorspace.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/eval.h"
#include "libavutil/pixdesc.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DrawBoxContext {
    const AVClass *class;
    int x, y, w, h;
    int thickness;
    char *color_str;
    unsigned char yuv_color[4];
    int invert_color; ///< invert luma color
    int vsub, hsub;   ///< chroma subsampling
    char *x_expr, *y_expr; ///< expression for x and y
    char *w_expr, *h_expr; ///< expression for width and height
    char *t_expr;          ///< expression for thickness
    int have_alpha;
    int replace;
} DrawBoxContext;
#define OFFSET(x) offsetof(DrawBoxContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_DRAWBOX_FILTER
#endif /* CONFIG_DRAWBOX_FILTER */
#if CONFIG_DRAWGRID_FILTER
#endif  /* CONFIG_DRAWGRID_FILTER */

#include <stdio.h>
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libavutil/eval.h"
#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/libm.h"
#include "libavutil/imgutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
typedef struct CropContext {
    const AVClass *class;
    int  x;             ///< x offset of the non-cropped area with respect to the input area
    int  y;             ///< y offset of the non-cropped area with respect to the input area
    int  w;             ///< width of the cropped area
    int  h;             ///< height of the cropped area

    AVRational out_sar; ///< output sample aspect ratio
    int keep_aspect;    ///< keep display aspect ratio when cropping
    int exact;          ///< exact cropping, for subsampled formats

    int max_step[4];    ///< max pixel step for each plane, expressed as a number of bytes
    int hsub, vsub;     ///< chroma subsampling
    char *x_expr, *y_expr, *w_expr, *h_expr;
    AVExpr *x_pexpr, *y_pexpr;  /* parsed expressions for x and y */
    double var_values[VAR_VARS_NB];
} CropContext;
#define OFFSET(x) offsetof(CropContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

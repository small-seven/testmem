#include <float.h>  /* DBL_MAX */
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/pixdesc.h"
#include "libavutil/colorspace.h"
#include "libavutil/imgutils.h"
#include "libavutil/parseutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "drawutils.h"
typedef struct PadContext {
    const AVClass *class;
    int w, h;               ///< output dimensions, a value of 0 will result in the input size
    int x, y;               ///< offsets of the input area with respect to the padded area
    int in_w, in_h;         ///< width and height for the padded input video, which has to be aligned to the chroma values in order to avoid chroma issues
    int inlink_w, inlink_h;
    AVRational aspect;

    char *w_expr;           ///< width  expression string
    char *h_expr;           ///< height expression string
    char *x_expr;           ///< width  expression string
    char *y_expr;           ///< height expression string
    uint8_t rgba_color[4];  ///< color for the padding area
    FFDrawContext draw;
    FFDrawColor color;

    int eval_mode;          ///< expression evaluation mode
} PadContext;
#define OFFSET(x) offsetof(PadContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

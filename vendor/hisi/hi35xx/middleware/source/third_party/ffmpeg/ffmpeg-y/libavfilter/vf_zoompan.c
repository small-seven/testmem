#include "libavutil/avassert.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libswscale/swscale.h"
typedef struct ZPcontext {
    const AVClass *class;
    char *zoom_expr_str;
    char *x_expr_str;
    char *y_expr_str;
    char *duration_expr_str;

    AVExpr *zoom_expr, *x_expr, *y_expr;

    int w, h;
    double x, y;
    double prev_zoom;
    int prev_nb_frames;
    struct SwsContext *sws;
    int64_t frame_count;
    const AVPixFmtDescriptor *desc;
    AVFrame *in;
    double var_values[VARS_NB];
    int nb_frames;
    int current_frame;
    int finished;
    AVRational framerate;
} ZPContext;
#define OFFSET(x) offsetof(ZPContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

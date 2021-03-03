#include "libavutil/opt.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/eval.h"
#include "libavutil/hwcontext.h"
#include "libavutil/avstring.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/mathematics.h"
#include "internal.h"
#include "avfilter.h"
#include "formats.h"
#include "video.h"
#include "framesync.h"
#include "qsvvpp.h"
#define MAIN    0
#define OVERLAY 1
#define OFFSET(x) offsetof(QSVOverlayContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
typedef struct QSVOverlayContext {
    const AVClass      *class;

    FFFrameSync fs;
    QSVVPPContext      *qsv;
    QSVVPPParam        qsv_param;
    mfxExtVPPComposite comp_conf;
    double             var_values[VAR_VARS_NB];

    char     *overlay_ox, *overlay_oy, *overlay_ow, *overlay_oh;
    uint16_t  overlay_alpha, overlay_pixel_alpha;

} QSVOverlayContext;
#define PASS_EXPR(e, s) {\
#undef PASS_EXPR

#include <math.h>
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct QPContext {
    const AVClass *class;
    char *qp_expr_str;
    int8_t lut[257];
    int h, qstride;
    int evaluate_per_mb;
} QPContext;
#define OFFSET(x) offsetof(QPContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

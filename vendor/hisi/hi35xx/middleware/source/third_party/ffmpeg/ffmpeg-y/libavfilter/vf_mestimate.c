#include "motion_estimation.h"
#include "libavcodec/mathops.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/motion_vector.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct MEContext {
    const AVClass *class;
    AVMotionEstContext me_ctx;
    int method;                         ///< motion estimation method

    int mb_size;                        ///< macroblock size
    int search_param;                   ///< search parameter
    int b_width, b_height, b_count;
    int log2_mb_size;

    AVFrame *prev, *cur, *next;

    int (*mv_table[3])[2][2];           ///< motion vectors of current & prev 2 frames
} MEContext;
#define OFFSET(x) offsetof(MEContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, 0, 0, FLAGS, unit }
#define SEARCH_MV(method)\
#define ADD_PRED(preds, px, py)\

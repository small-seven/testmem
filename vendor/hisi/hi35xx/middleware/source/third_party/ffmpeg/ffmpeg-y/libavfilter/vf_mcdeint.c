#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/avcodec.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct MCDeintContext {
    const AVClass *class;
    int mode;           ///< MCDeintMode
    int parity;         ///< MCDeintParity
    int qp;
    AVCodecContext *enc_ctx;
} MCDeintContext;
#define OFFSET(x) offsetof(MCDeintContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, INT_MIN, INT_MAX, FLAGS, unit }
#define DELTA(j) av_clip(j, -x, w-1-x)
#define GET_SCORE_EDGE(j)\
#define GET_SCORE(j)\
#define CHECK_EDGE(j)\
#define CHECK(j)\

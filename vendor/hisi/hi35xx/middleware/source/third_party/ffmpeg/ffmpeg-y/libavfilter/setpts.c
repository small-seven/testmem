#include <inttypes.h>
#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct SetPTSContext {
    const AVClass *class;
    char *expr_str;
    AVExpr *expr;
    double var_values[VAR_VARS_NB];
    enum AVMediaType type;
} SetPTSContext;
#define D2TS(d)  (isnan(d) ? AV_NOPTS_VALUE : (int64_t)(d))
#define TS2D(ts) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts))
#define TS2T(ts, tb) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts)*av_q2d(tb))
#define BUF_SIZE 64
#define d2istr(v) double2int64str((char[BUF_SIZE]){0}, v)
#define OFFSET(x) offsetof(SetPTSContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_SETPTS_FILTER
#define setpts_options options
#endif /* CONFIG_SETPTS_FILTER */
#if CONFIG_ASETPTS_FILTER
#define asetpts_options options
#endif /* CONFIG_ASETPTS_FILTER */

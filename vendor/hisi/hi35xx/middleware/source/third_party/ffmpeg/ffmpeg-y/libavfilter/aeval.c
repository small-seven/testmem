#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct EvalContext {
    const AVClass *class;
    char *sample_rate_str;
    int sample_rate;
    int64_t chlayout;
    char *chlayout_str;
    int nb_channels;            ///< number of output channels
    int nb_in_channels;         ///< number of input channels
    int same_chlayout;          ///< set output as input channel layout
    int64_t pts;
    AVExpr **expr;
    char *exprs;
    int nb_samples;             ///< number of samples per requested frame
    int64_t duration;
    uint64_t n;
    double var_values[VAR_VARS_NB];
    double *channel_values;
    int64_t out_channel_layout;
} EvalContext;
#define OFFSET(x) offsetof(EvalContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define ADD_EXPRESSION(expr_) do {                                      \
#if CONFIG_AEVALSRC_FILTER
#endif /* CONFIG_AEVALSRC_FILTER */
#define OFFSET(x) offsetof(EvalContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define TS2T(ts, tb) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts)*av_q2d(tb))
#if CONFIG_AEVAL_FILTER
#endif /* CONFIG_AEVAL_FILTER */

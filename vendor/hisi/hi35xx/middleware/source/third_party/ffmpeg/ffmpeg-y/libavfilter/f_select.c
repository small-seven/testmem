#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/fifo.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "scene_sad.h"
typedef struct SelectContext {
    const AVClass *class;
    char *expr_str;
    AVExpr *expr;
    double var_values[VAR_VARS_NB];
    int do_scene_detect;            ///< 1 if the expression requires scene detection variables, 0 otherwise
    ff_scene_sad_fn sad;            ///< Sum of the absolute difference function (scene detect only)
    double prev_mafd;               ///< previous MAFD                           (scene detect only)
    AVFrame *prev_picref;           ///< previous frame                          (scene detect only)
    double select;
    int select_out;                 ///< mark the selected output pad index
    int nb_outputs;
} SelectContext;
#define OFFSET(x) offsetof(SelectContext, x)
#define DEFINE_OPTIONS(filt_name, FLAGS)                            \
#define INTERLACE_TYPE_P 0
#define INTERLACE_TYPE_T 1
#define INTERLACE_TYPE_B 2
#define D2TS(d)  (isnan(d) ? AV_NOPTS_VALUE : (int64_t)(d))
#define TS2D(ts) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts))
#if CONFIG_ASELECT_FILTER
#endif /* CONFIG_ASELECT_FILTER */
#if CONFIG_SELECT_FILTER
#endif /* CONFIG_SELECT_FILTER */

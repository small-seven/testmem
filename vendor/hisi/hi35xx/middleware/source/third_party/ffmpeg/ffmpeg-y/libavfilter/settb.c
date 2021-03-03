#include <inttypes.h>
#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/rational.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct SetTBContext {
    const AVClass *class;
    char *tb_expr;
    double var_values[VAR_VARS_NB];
} SetTBContext;
#define OFFSET(x) offsetof(SetTBContext, x)
#define DEFINE_OPTIONS(filt_name, filt_type)                                               \
#if CONFIG_SETTB_FILTER
#endif /* CONFIG_SETTB_FILTER */
#if CONFIG_ASETTB_FILTER
#endif /* CONFIG_ASETTB_FILTER */

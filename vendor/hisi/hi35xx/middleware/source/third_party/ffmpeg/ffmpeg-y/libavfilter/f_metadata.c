#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "libavformat/avio.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct MetadataContext {
    const AVClass *class;

    int mode;
    char *key;
    char *value;
    int function;

    char *expr_str;
    AVExpr *expr;
    double var_values[VAR_VARS_NB];

    AVIOContext* avio_context;
    char *file_str;

    int (*compare)(struct MetadataContext *s,
                   const char *value1, const char *value2);
    void (*print)(AVFilterContext *ctx, const char *msg, ...) av_printf_format(2, 3);
} MetadataContext;
#define OFFSET(x) offsetof(MetadataContext, x)
#define DEFINE_OPTIONS(filt_name, FLAGS) \
#if CONFIG_AMETADATA_FILTER
#endif /* CONFIG_AMETADATA_FILTER */
#if CONFIG_METADATA_FILTER
#endif /* CONFIG_METADATA_FILTER */

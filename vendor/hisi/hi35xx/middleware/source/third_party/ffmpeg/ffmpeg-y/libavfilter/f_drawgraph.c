#include "float.h"
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DrawGraphContext {
    const AVClass *class;

    char          *key[4];
    float         min, max;
    char          *fg_str[4];
    AVExpr        *fg_expr[4];
    uint8_t       bg[4];
    int           mode;
    int           slide;
    int           w, h;

    AVFrame       *out;
    int           x;
    int           prev_y[4];
    int           first[4];
    float         *values[4];
    int           values_size[4];
    int           nb_values;
} DrawGraphContext;
#define OFFSET(x) offsetof(DrawGraphContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_DRAWGRAPH_FILTER
#endif // CONFIG_DRAWGRAPH_FILTER
#if CONFIG_ADRAWGRAPH_FILTER
#define adrawgraph_options drawgraph_options
#endif // CONFIG_ADRAWGRAPH_FILTER

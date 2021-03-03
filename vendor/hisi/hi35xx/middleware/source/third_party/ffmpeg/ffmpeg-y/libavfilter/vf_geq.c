#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
typedef struct GEQContext {
    const AVClass *class;
    AVExpr *e[4];               ///< expressions for each plane
    char *expr_str[4+3];        ///< expression strings for each plane
    AVFrame *picref;            ///< current input buffer
    uint8_t *dst;               ///< reference pointer to the 8bits output
    uint16_t *dst16;            ///< reference pointer to the 16bits output
    double values[VAR_VARS_NB]; ///< expression values
    int hsub, vsub;             ///< chroma subsampling
    int planes;                 ///< number of planes
    int is_rgb;
    int bps;
} GEQContext;
#define OFFSET(x) offsetof(GEQContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    int height;
    int width;
    int plane;
    int linesize;
} ThreadData;

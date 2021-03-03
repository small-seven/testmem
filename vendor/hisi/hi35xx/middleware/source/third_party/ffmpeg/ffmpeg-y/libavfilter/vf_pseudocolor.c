#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct PseudoColorContext {
    const AVClass *class;
    int max;
    int index;
    int nb_planes;
    int color;
    int linesize[4];
    int width[4], height[4];
    double var_values[VAR_VARS_NB];
    char   *comp_expr_str[4];
    AVExpr *comp_expr[4];
    float lut[4][256*256];

    void (*filter[4])(int max, int width, int height,
                      const uint8_t *index, const uint8_t *src,
                      uint8_t *dst,
                      ptrdiff_t ilinesize,
                      ptrdiff_t slinesize,
                      ptrdiff_t dlinesize,
                      float *lut);
} PseudoColorContext;
#define OFFSET(x) offsetof(PseudoColorContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

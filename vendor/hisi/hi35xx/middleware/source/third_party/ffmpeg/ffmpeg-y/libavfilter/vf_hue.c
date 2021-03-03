#include <float.h>
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define SAT_MIN_VAL -10
#define SAT_MAX_VAL 10
typedef struct HueContext {
    const    AVClass *class;
    float    hue_deg; /* hue expressed in degrees */
    float    hue; /* hue expressed in radians */
    char     *hue_deg_expr;
    char     *hue_expr;
    AVExpr   *hue_deg_pexpr;
    AVExpr   *hue_pexpr;
    float    saturation;
    char     *saturation_expr;
    AVExpr   *saturation_pexpr;
    float    brightness;
    char     *brightness_expr;
    AVExpr   *brightness_pexpr;
    int      hsub;
    int      vsub;
    int is_first;
    int32_t hue_sin;
    int32_t hue_cos;
    double   var_values[VAR_NB];
    uint8_t  lut_l[256];
    uint8_t  lut_u[256][256];
    uint8_t  lut_v[256][256];
    uint16_t  lut_l16[65536];
    uint16_t  lut_u10[1024][1024];
    uint16_t  lut_v10[1024][1024];
} HueContext;
#define OFFSET(x) offsetof(HueContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SET_EXPR(expr, option)                                          \
#undef SET_EXPR
#define TS2D(ts) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts))
#define TS2T(ts, tb) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts) * av_q2d(tb))
#define SET_EXPR(expr, option)                                          \

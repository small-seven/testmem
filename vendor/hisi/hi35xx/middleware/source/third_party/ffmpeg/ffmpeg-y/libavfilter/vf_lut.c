#include "libavutil/attributes.h"
#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct LutContext {
    const AVClass *class;
    uint16_t lut[4][256 * 256];  ///< lookup table for each component
    char   *comp_expr_str[4];
    AVExpr *comp_expr[4];
    int hsub, vsub;
    double var_values[VAR_VARS_NB];
    int is_rgb, is_yuv;
    int is_planar;
    int is_16bit;
    int step;
    int negate_alpha; /* only used by negate */
} LutContext;
#define Y 0
#define U 1
#define V 2
#define R 0
#define G 1
#define B 2
#define A 3
#define OFFSET(x) offsetof(LutContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define YUV_FORMATS                                         \
#define RGB_FORMATS                             \
#define GRAY_FORMATS                            \
#define LOAD_PACKED_COMMON\
#if HAVE_BIGENDIAN
#else
#endif
#define LOAD_PLANAR_COMMON\
#define PLANAR_COMMON\
#if HAVE_BIGENDIAN
#else
#endif
#define PACKED_THREAD_DATA\
#define PLANAR_THREAD_DATA\
#define DEFINE_LUT_FILTER(name_, description_)                          \
#if CONFIG_LUT_FILTER
#define lut_options options
#endif
#if CONFIG_LUTYUV_FILTER
#define lutyuv_options options
#endif
#if CONFIG_LUTRGB_FILTER
#define lutrgb_options options
#endif
#if CONFIG_NEGATE_FILTER
#endif

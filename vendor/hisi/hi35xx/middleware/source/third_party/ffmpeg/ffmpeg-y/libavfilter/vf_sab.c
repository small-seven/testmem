#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libswscale/swscale.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct FilterParam {
    float radius;
    float pre_filter_radius;
    float strength;
    float quality;
    struct SwsContext *pre_filter_context;
    uint8_t *pre_filter_buf;
    int pre_filter_linesize;
    int dist_width;
    int dist_linesize;
    int *dist_coeff;
#define COLOR_DIFF_COEFF_SIZE 512
    int color_diff_coeff[COLOR_DIFF_COEFF_SIZE];
} FilterParam;
typedef struct SabContext {
    const AVClass *class;
    FilterParam  luma;
    FilterParam  chroma;
    int          hsub;
    int          vsub;
    unsigned int sws_flags;
} SabContext;
#define RADIUS_MIN 0.1
#define RADIUS_MAX 4.0
#define PRE_FILTER_RADIUS_MIN 0.1
#define PRE_FILTER_RADIUS_MAX 2.0
#define STRENGTH_MIN 0.1
#define STRENGTH_MAX 100.0
#define OFFSET(x) offsetof(SabContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define NB_PLANES 4
#define UPDATE_FACTOR do {                                              \

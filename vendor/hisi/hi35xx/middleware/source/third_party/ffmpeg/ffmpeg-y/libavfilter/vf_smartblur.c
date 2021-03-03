#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libswscale/swscale.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define RADIUS_MIN 0.1
#define RADIUS_MAX 5.0
#define STRENGTH_MIN -1.0
#define STRENGTH_MAX 1.0
#define THRESHOLD_MIN -30
#define THRESHOLD_MAX 30
typedef struct FilterParam {
    float              radius;
    float              strength;
    int                threshold;
    float              quality;
    struct SwsContext *filter_context;
} FilterParam;
typedef struct SmartblurContext {
    const AVClass *class;
    FilterParam  luma;
    FilterParam  chroma;
    int          hsub;
    int          vsub;
    unsigned int sws_flags;
} SmartblurContext;
#define OFFSET(x) offsetof(SmartblurContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "bbox.h"
#include "internal.h"
typedef struct BBoxContext {
    const AVClass *class;
    int min_val;
} BBoxContext;
#define OFFSET(x) offsetof(BBoxContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SET_META(key, value) \

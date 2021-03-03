#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "vmaf_motion.h"
#define BIT_SHIFT 15
typedef struct VMAFMotionContext {
    const AVClass *class;
    VMAFMotionData data;
    FILE *stats_file;
    char *stats_file_str;
} VMAFMotionContext;
#define OFFSET(x) offsetof(VMAFMotionContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define conv_y_fn(type, bits) \

#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#include "video.h"
#define WIDTH 512
#define HEIGHT 512
typedef struct MPTestContext {
    const AVClass *class;
    AVRational frame_rate;
    int64_t pts, max_pts, duration;
    int hsub, vsub;
    int test;           ///< test_type
} MPTestContext;
#define OFFSET(x) offsetof(MPTestContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

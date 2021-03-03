#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct BPNContext {
    const AVClass *class;

    int bitplane;
    int filter;

    int nb_planes;
    int planeheight[4];
    int planewidth[4];
    int depth;
} BPNContext;
#define OFFSET(x) offsetof(BPNContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define CHECK_BIT(x, a, b, c) { \

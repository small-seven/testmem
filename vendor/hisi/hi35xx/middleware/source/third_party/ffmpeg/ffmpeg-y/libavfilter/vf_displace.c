#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
typedef struct DisplaceContext {
    const AVClass *class;
    int width[4], height[4];
    enum EdgeMode edge;
    int nb_planes;
    int nb_components;
    int step;
    uint8_t blank[4];
    FFFrameSync fs;

    void (*displace)(struct DisplaceContext *s, const AVFrame *in,
                     const AVFrame *xpic, const AVFrame *ypic, AVFrame *out);
} DisplaceContext;
#define OFFSET(x) offsetof(DisplaceContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

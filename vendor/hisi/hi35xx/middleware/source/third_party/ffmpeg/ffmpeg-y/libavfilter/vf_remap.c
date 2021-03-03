#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
typedef struct RemapContext {
    const AVClass *class;
    int format;

    int nb_planes;
    int nb_components;
    int step;

    FFFrameSync fs;

    int (*remap_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} RemapContext;
#define OFFSET(x) offsetof(RemapContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    AVFrame *in, *xin, *yin, *out;
    int nb_planes;
    int nb_components;
    int step;
} ThreadData;
#define DEFINE_REMAP_PLANAR_FUNC(name, bits, div)                                           \
#define DEFINE_REMAP_PACKED_FUNC(name, bits, div)                                           \

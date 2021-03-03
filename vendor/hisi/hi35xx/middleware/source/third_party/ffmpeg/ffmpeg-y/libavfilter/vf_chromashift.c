#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "framesync.h"
#include "video.h"
typedef struct ChromaShiftContext {
    const AVClass *class;
    int cbh, cbv;
    int crh, crv;
    int rh, rv;
    int gh, gv;
    int bh, bv;
    int ah, av;
    int edge;

    int nb_planes;
    int depth;
    int height[4];
    int width[4];
    int linesize[4];

    AVFrame *in;

    int is_rgbashift;
    int (*filter_slice)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ChromaShiftContext;
#define DEFINE_SMEAR(depth, type, div)                                                    \
#define DEFINE_WRAP(depth, type, div)                                                     \
#define DEFINE_RGBASMEAR(depth, type, div)                                                    \
#define DEFINE_RGBAWRAP(depth, type, div)                                                     \
#define OFFSET(x) offsetof(ChromaShiftContext, x)
#define VF AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

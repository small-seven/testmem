#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct PhaseContext {
    const AVClass *class;
    int mode;                   ///<PhaseMode
    AVFrame *frame; /* previous frame */
    int nb_planes;
    int planeheight[4];
    int linesize[4];
} PhaseContext;
#define OFFSET(x) offsetof(PhaseContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, 0, 0, FLAGS, unit }
#define DIFF(a, as, b, bs) ((t) = ((*(a) - (b)[bs]) << 2) + (a)[(as) << 1] - (b)[-(bs)], (t) * (t))

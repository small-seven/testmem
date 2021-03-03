#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct SwapRectContext {
    const AVClass *class;
    char *w, *h;
    char *x1, *y1;
    char *x2, *y2;

    int nb_planes;
    int pixsteps[4];

    const AVPixFmtDescriptor *desc;
    uint8_t *temp;
} SwapRectContext;
#define OFFSET(x) offsetof(SwapRectContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

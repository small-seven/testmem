#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DespillContext {
    const AVClass *class;

    int co[4]; /* color offsets rgba */

    int alpha;
    int type;
    float spillmix;
    float spillexpand;
    float redscale;
    float greenscale;
    float bluescale;
    float brightness;
} DespillContext;
#define OFFSET(x) offsetof(DespillContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

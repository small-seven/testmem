#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
typedef struct OWDenoiseContext {
    const AVClass *class;
    double luma_strength;
    double chroma_strength;
    int depth;
    float *plane[16+1][4];
    int linesize;
    int hsub, vsub;
    int pixel_depth;
} OWDenoiseContext;
#define OFFSET(x) offsetof(OWDenoiseContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

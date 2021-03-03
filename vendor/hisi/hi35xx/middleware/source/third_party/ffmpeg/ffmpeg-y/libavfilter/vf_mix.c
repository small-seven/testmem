#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "framesync.h"
#include "video.h"
typedef struct MixContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    char *weights_str;
    int nb_inputs;
    int duration;
    float *weights;
    float scale;
    float wfactor;

    int tmix;
    int nb_frames;

    int depth;
    int max;
    int nb_planes;
    int linesize[4];
    int height[4];

    AVFrame **frames;
    FFFrameSync fs;
} MixContext;
typedef struct ThreadData {
    AVFrame **in, *out;
} ThreadData;
#define OFFSET(x) offsetof(MixContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_MIX_FILTER
#endif /* CONFIG_MIX_FILTER */
#if CONFIG_TMIX_FILTER
#endif /* CONFIG_TMIX_FILTER */

#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct AmplifyContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    int radius;
    float factor;
    float threshold;
    float tolerance;
    int planes;

    int llimit;
    int hlimit;
    int nb_inputs;
    int nb_frames;

    int depth;
    int nb_planes;
    int linesize[4];
    int height[4];

    AVFrame **frames;
} AmplifyContext;
typedef struct ThreadData {
    AVFrame **in, *out;
} ThreadData;
#define OFFSET(x) offsetof(AmplifyContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

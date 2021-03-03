#include <float.h>
#include "libavutil/imgutils.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct VagueDenoiserContext {
    const AVClass *class;

    float threshold;
    float percent;
    int method;
    int nsteps;
    int planes;

    int depth;
    int bpc;
    int peak;
    int nb_planes;
    int planeheight[4];
    int planewidth[4];

    float *block;
    float *in;
    float *out;
    float *tmp;

    int hlowsize[4][32];
    int hhighsize[4][32];
    int vlowsize[4][32];
    int vhighsize[4][32];

    void (*thresholding)(float *block, const int width, const int height,
                         const int stride, const float threshold,
                         const float percent, const int nsteps);
} VagueDenoiserContext;
#define OFFSET(x) offsetof(VagueDenoiserContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#define NPAD 10

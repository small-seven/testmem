#include <float.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "colorspace.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct TonemapContext {
    const AVClass *class;

    enum TonemapAlgorithm tonemap;
    double param;
    double desat;
    double peak;

    const struct LumaCoefficients *coeffs;
} TonemapContext;
#define MIX(x,y,a) (x) * (1 - (a)) + (y) * (a)
typedef struct ThreadData {
    AVFrame *in, *out;
    const AVPixFmtDescriptor *desc;
    double peak;
} ThreadData;
#define OFFSET(x) offsetof(TonemapContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

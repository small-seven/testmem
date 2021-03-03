#if defined(_MSC_VER)
#define X265_API_IMPORTS 1
#endif
#include <x265.h>
#include <float.h>
#include "libavutil/internal.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "internal.h"
typedef struct libx265Context {
    const AVClass *class;

    x265_encoder *encoder;
    x265_param   *params;
    const x265_api *api;

    float crf;
    int   forced_idr;
    char *preset;
    char *tune;
    char *profile;
    char *x265_opts;
} libx265Context;
#if FF_API_CODED_FRAME
#endif
#if X265_BUILD >= 130
#else
#endif
#define OFFSET(x) offsetof(libx265Context, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM

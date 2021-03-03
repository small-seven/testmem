#include <float.h>
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avstring.h"
#define NS(n) ((n) < 0 ? (int)((n)*65536.0-0.5+DBL_EPSILON) : (int)((n)*65536.0+0.5))
#define CB(n) av_clip_uint8(n)
typedef struct ColorMatrixContext {
    const AVClass *class;
    int yuv_convert[25][3][3];
    int interlaced;
    int source, dest;        ///< ColorMode
    int mode;
    int hsub, vsub;
} ColorMatrixContext;
typedef struct ThreadData {
    AVFrame *dst;
    const AVFrame *src;
    int c2;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;
} ThreadData;
#define OFFSET(x) offsetof(ColorMatrixContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define ma m[0][0]
#define mb m[0][1]
#define mc m[0][2]
#define md m[1][0]
#define me m[1][1]
#define mf m[1][2]
#define mg m[2][0]
#define mh m[2][1]
#define mi m[2][2]
#define ima im[0][0]
#define imb im[0][1]
#define imc im[0][2]
#define imd im[1][0]
#define ime im[1][1]
#define imf im[1][2]
#define img im[2][0]
#define imh im[2][1]
#define imi im[2][2]

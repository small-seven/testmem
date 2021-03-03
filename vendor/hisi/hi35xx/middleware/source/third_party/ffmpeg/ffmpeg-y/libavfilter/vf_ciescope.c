#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct CiescopeContext {
    const AVClass *class;
    int color_system;
    unsigned gamuts;
    int size;
    int show_white;
    int correct_gamma;
    int cie;
    float intensity;
    float contrast;
    int background;

    double log2lin[65536];
    double igamma;
    double i[3][3];
    double m[3][3];
    AVFrame *f;
    void (*filter)(AVFilterContext *ctx, AVFrame *in, double *cx, double *cy, int x, int y);
} CiescopeContext;
#define OFFSET(x) offsetof(CiescopeContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define C     0.310063, 0.316158
#define E     1.0/3.0, 1.0/3.0
#define D50   0.34570, 0.3585
#define D65   0.312713, 0.329016
#define GAMMA_REC709    0.      /* Rec. 709 */
#define Sz(x) (((x) * (int)FFMIN(w, h)) / 512)

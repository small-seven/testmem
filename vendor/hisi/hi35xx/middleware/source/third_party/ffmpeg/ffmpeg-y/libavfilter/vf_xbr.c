#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#define LB_MASK       0x00FEFEFE
#define RED_BLUE_MASK 0x00FF00FF
#define GREEN_MASK    0x0000FF00
#ifdef PI
#undef PI
#endif
typedef int (*xbrfunc_t)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);

typedef struct XBRContext {
    const AVClass *class;
    int n;
    xbrfunc_t func;
    uint32_t rgbtoyuv[1<<24];
} XBRContext;
typedef struct ThreadData {
    AVFrame *in, *out;
    const uint32_t *rgbtoyuv;
} ThreadData;
#define OFFSET(x) offsetof(XBRContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define YMASK 0xff0000
#define UMASK 0x00ff00
#define VMASK 0x0000ff
#define ABSDIFF(a,b) (abs((int)(a)-(int)(b)))
#define ALPHA_BLEND_128_W(a, b) ((((a) & LB_MASK) >> 1) + (((b) & LB_MASK) >> 1))
#define ALPHA_BLEND_BASE(a, b, m, s) (  (RED_BLUE_MASK & (((a) & RED_BLUE_MASK) + (((((b) & RED_BLUE_MASK) - ((a) & RED_BLUE_MASK)) * (m)) >> (s)))) \
#define ALPHA_BLEND_32_W(a, b)  ALPHA_BLEND_BASE(a, b, 1, 3)
#define ALPHA_BLEND_64_W(a, b)  ALPHA_BLEND_BASE(a, b, 1, 2)
#define ALPHA_BLEND_192_W(a, b) ALPHA_BLEND_BASE(a, b, 3, 2)
#define ALPHA_BLEND_224_W(a, b) ALPHA_BLEND_BASE(a, b, 7, 3)
#define df(A, B) pixel_diff(A, B, r2y)
#define eq(A, B) (df(A, B) < 155)
#define FILT2(PE, PI, PH, PF, PG, PC, PD, PB, PA, G5, C4, G0, D0, C1, B1, F4, I4, H5, I5, A0, A1,   \
#define FILT3(PE, PI, PH, PF, PG, PC, PD, PB, PA, G5, C4, G0, D0, C1, B1, F4, I4, H5, I5, A0, A1,   \
#define FILT4(PE, PI, PH, PF, PG, PC, PD, PB, PA, G5, C4, G0, D0, C1, B1, F4, I4, H5, I5, A0, A1,   \
#define XBR_FUNC(size) \

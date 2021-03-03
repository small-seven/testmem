#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
typedef int (*hqxfunc_t)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);

typedef struct HQXContext {
    const AVClass *class;
    int n;
    hqxfunc_t func;
    uint32_t rgbtoyuv[1<<24];
} HQXContext;
typedef struct ThreadData {
    AVFrame *in, *out;
    const uint32_t *rgbtoyuv;
} ThreadData;
#define OFFSET(x) offsetof(HQXContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define YMASK 0xff0000
#define UMASK 0x00ff00
#define VMASK 0x0000ff
#define ABSDIFF(a,b) (abs((int)(a)-(int)(b)))
#define P(m, r) ((k_shuffled & (m)) == (r))
#define DROP4(z) ((z) > 4 ? (z)-1 : (z))
#define SHF(x, rot, n) (((x) >> ((rot) ? 7-DROP4(n) : DROP4(n)) & 1) << DROP4(p##n))
#define WDIFF(c1, c2) yuv_diff(rgb2yuv(r2y, c1), rgb2yuv(r2y, c2))
#define INTERP_BOOTSTRAP(rot)                                           \
#define HQX_FUNC(size) \

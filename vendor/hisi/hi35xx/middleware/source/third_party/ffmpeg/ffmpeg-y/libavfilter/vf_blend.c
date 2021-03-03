#include "libavutil/imgutils.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "avfilter.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
#include "blend.h"
#define TOP    0
#define BOTTOM 1
typedef struct BlendContext {
    const AVClass *class;
    FFFrameSync fs;
    int hsub, vsub;             ///< chroma subsampling values
    int nb_planes;
    char *all_expr;
    enum BlendMode all_mode;
    double all_opacity;

    int depth;
    FilterParams params[4];
    int tblend;
    AVFrame *prev_frame;        /* only used with tblend */
} BlendContext;
typedef struct ThreadData {
    const AVFrame *top, *bottom;
    AVFrame *dst;
    AVFilterLink *inlink;
    int plane;
    int w, h;
    FilterParams *param;
} ThreadData;
#define COMMON_OPTIONS \
#define OFFSET(x) offsetof(BlendContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define COPY(src, depth)                                                            \
#undef COPY
#define DEFINE_BLEND8(name, expr)                                              \
#define DEFINE_BLEND16(name, expr, depth)                                            \
#define A top[j]
#define B bottom[j]
#define MULTIPLY(x, a, b) ((x) * (((a) * (b)) / 255))
#define SCREEN(x, a, b)   (255 - (x) * ((255 - (a)) * (255 - (b)) / 255))
#define BURN(a, b)        (((a) == 0) ? (a) : FFMAX(0, 255 - ((255 - (b)) << 8) / (a)))
#define DODGE(a, b)       (((a) == 255) ? (a) : FFMIN(255, (((b) << 8) / (255 - (a)))))
#undef MULTIPLY
#undef SCREEN
#undef BURN
#undef DODGE
#define MULTIPLY(x, a, b) ((x) * (((a) * (b)) / 65535))
#define SCREEN(x, a, b)   (65535 - (x) * ((65535 - (a)) * (65535 - (b)) / 65535))
#define BURN(a, b)        (((a) == 0) ? (a) : FFMAX(0, 65535 - ((65535 - (b)) << 16) / (a)))
#define DODGE(a, b)       (((a) == 65535) ? (a) : FFMIN(65535, (((b) << 16) / (65535 - (a)))))
#undef MULTIPLY
#undef SCREEN
#undef BURN
#undef DODGE
#define MULTIPLY(x, a, b) ((x) * (((a) * (b)) / 1023))
#define SCREEN(x, a, b)   (1023 - (x) * ((1023 - (a)) * (1023 - (b)) / 1023))
#define BURN(a, b)        (((a) == 0) ? (a) : FFMAX(0, 1023 - ((1023 - (b)) << 10) / (a)))
#define DODGE(a, b)       (((a) == 1023) ? (a) : FFMIN(1023, (((b) << 10) / (1023 - (a)))))
#undef MULTIPLY
#undef SCREEN
#undef BURN
#undef DODGE
#define MULTIPLY(x, a, b) ((x) * (((a) * (b)) / 4095))
#define SCREEN(x, a, b)   (4095 - (x) * ((4095 - (a)) * (4095 - (b)) / 4095))
#define BURN(a, b)        (((a) == 0) ? (a) : FFMAX(0, 4095 - ((4095 - (b)) << 12) / (a)))
#define DODGE(a, b)       (((a) == 4095) ? (a) : FFMIN(4095, (((b) << 12) / (4095 - (a)))))
#undef MULTIPLY
#undef SCREEN
#undef BURN
#undef DODGE
#define MULTIPLY(x, a, b) ((x) * (((a) * (b)) / 511))
#define SCREEN(x, a, b)   (511 - (x) * ((511 - (a)) * (511 - (b)) / 511))
#define BURN(a, b)        (((a) == 0) ? (a) : FFMAX(0, 511 - ((511 - (b)) << 9) / (a)))
#define DODGE(a, b)       (((a) == 511) ? (a) : FFMIN(511, (((b) << 9) / (511 - (a)))))
#define DEFINE_BLEND_EXPR(type, name, div)                                     \
#define DEFINE_INIT_BLEND_FUNC(depth, nbits)                                              \
#if CONFIG_BLEND_FILTER
#endif
#if CONFIG_TBLEND_FILTER
#endif

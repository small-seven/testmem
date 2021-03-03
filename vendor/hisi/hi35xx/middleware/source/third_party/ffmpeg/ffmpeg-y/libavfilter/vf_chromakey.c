#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ChromakeyContext {
    const AVClass *class;

    uint8_t chromakey_rgba[4];
    uint8_t chromakey_uv[2];

    float similarity;
    float blend;

    int is_yuv;

    int hsub_log2;
    int vsub_log2;

    int (*do_slice)(AVFilterContext *ctx, void *arg,
                    int jobnr, int nb_jobs);
} ChromakeyContext;
#define FIXNUM(x) lrint((x) * (1 << 10))
#define RGB_TO_U(rgb) (((- FIXNUM(0.16874) * rgb[0] - FIXNUM(0.33126) * rgb[1] + FIXNUM(0.50000) * rgb[2] + (1 << 9) - 1) >> 10) + 128)
#define RGB_TO_V(rgb) (((  FIXNUM(0.50000) * rgb[0] - FIXNUM(0.41869) * rgb[1] - FIXNUM(0.08131) * rgb[2] + (1 << 9) - 1) >> 10) + 128)
#define OFFSET(x) offsetof(ChromakeyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

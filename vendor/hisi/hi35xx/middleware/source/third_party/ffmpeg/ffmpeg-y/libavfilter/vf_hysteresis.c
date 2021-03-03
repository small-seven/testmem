#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "framesync.h"
#define OFFSET(x) offsetof(HysteresisContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct HysteresisContext {
    const AVClass *class;
    FFFrameSync fs;

    int planes;
    int threshold;

    int width[4], height[4];
    int nb_planes;
    int depth;

    uint8_t *map;
    uint32_t *xy;
    int index;

    void (*hysteresis)(struct HysteresisContext *s, const uint8_t *bsrc, const uint8_t *osrc, uint8_t *dst,
                       ptrdiff_t blinesize, ptrdiff_t olinesize,
                       ptrdiff_t destlinesize,
                       int w, int h);
} HysteresisContext;

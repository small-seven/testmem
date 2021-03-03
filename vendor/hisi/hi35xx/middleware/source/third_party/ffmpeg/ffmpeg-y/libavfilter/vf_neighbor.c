#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
typedef struct NContext {
    const AVClass *class;
    int planeheight[4];
    int planewidth[4];
    int nb_planes;
    int threshold[4];
    int coordinates;

    int depth;
    int max;
    int bpc;

    void (*filter)(uint8_t *dst, const uint8_t *p1, int width,
                   int threshold, const uint8_t *coordinates[], int coord,
                   int maxc);
} NContext;
#define OFFSET(x) offsetof(NContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define DEFINE_NEIGHBOR_FILTER(name_, description_)          \
#if CONFIG_EROSION_FILTER
#endif /* CONFIG_EROSION_FILTER */
#if CONFIG_DILATION_FILTER
#endif /* CONFIG_DILATION_FILTER */
#if CONFIG_DEFLATE_FILTER
#endif /* CONFIG_DEFLATE_FILTER */
#if CONFIG_INFLATE_FILTER
#endif /* CONFIG_INFLATE_FILTER */

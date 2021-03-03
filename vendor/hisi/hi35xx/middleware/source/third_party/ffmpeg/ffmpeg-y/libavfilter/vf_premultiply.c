#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
typedef struct ThreadData {
    AVFrame *m, *a, *d;
} ThreadData;
typedef struct PreMultiplyContext {
    const AVClass *class;
    int width[4], height[4];
    int linesize[4];
    int nb_planes;
    int planes;
    int inverse;
    int inplace;
    int half, depth, offset, max;
    FFFrameSync fs;

    void (*premultiply[4])(const uint8_t *msrc, const uint8_t *asrc,
                           uint8_t *dst,
                           ptrdiff_t mlinesize, ptrdiff_t alinesize,
                           ptrdiff_t dlinesize,
                           int w, int h,
                           int half, int shift, int offset);
} PreMultiplyContext;
#define OFFSET(x) offsetof(PreMultiplyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define premultiply_options options
#if CONFIG_PREMULTIPLY_FILTER
#endif /* CONFIG_PREMULTIPLY_FILTER */
#if CONFIG_UNPREMULTIPLY_FILTER
#define unpremultiply_options options
#endif /* CONFIG_UNPREMULTIPLY_FILTER */

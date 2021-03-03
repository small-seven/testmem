#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/qsort.h"
#include "avfilter.h"
#define FF_BUFQUEUE_SIZE 129
#include "bufferqueue.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define SIZE FF_BUFQUEUE_SIZE
typedef struct DeflickerContext {
    const AVClass *class;

    int size;
    int mode;
    int bypass;

    int eof;
    int depth;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];

    uint64_t *histogram;
    float luminance[SIZE];
    float sorted[SIZE];

    struct FFBufQueue q;
    int available;

    void (*get_factor)(AVFilterContext *ctx, float *f);
    float (*calc_avgy)(AVFilterContext *ctx, AVFrame *in);
    int (*deflicker)(AVFilterContext *ctx, const uint8_t *src, ptrdiff_t src_linesize,
                     uint8_t *dst, ptrdiff_t dst_linesize, int w, int h, float f);
} DeflickerContext;
#define OFFSET(x) offsetof(DeflickerContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

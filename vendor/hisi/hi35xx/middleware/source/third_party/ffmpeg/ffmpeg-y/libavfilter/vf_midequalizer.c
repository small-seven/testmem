#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "framesync.h"
typedef struct MidEqualizerContext {
    const AVClass *class;
    int width[2][4], height[2][4];
    int nb_planes;
    int planes;
    int histogram_size;
    float *histogram[2];
    unsigned *cchange;
    FFFrameSync fs;

    void (*midequalizer)(const uint8_t *in0, const uint8_t *in1,
                         uint8_t *dst,
                         ptrdiff_t linesize1, ptrdiff_t linesize2,
                         ptrdiff_t dlinesize,
                         int w0, int h0,
                         int w1, int h1,
                         float *histogram1, float *histogram2,
                         unsigned *cchange, size_t hsize);
} MidEqualizerContext;
#define OFFSET(x) offsetof(MidEqualizerContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

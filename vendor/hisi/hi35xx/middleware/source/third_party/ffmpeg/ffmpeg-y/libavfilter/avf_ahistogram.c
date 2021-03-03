#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
typedef struct AudioHistogramContext {
    const AVClass *class;
    AVFrame *out;
    int w, h;
    AVRational frame_rate;
    uint64_t *achistogram;
    uint64_t *shistogram;
    int ascale;
    int scale;
    float phisto;
    int histogram_h;
    int apos;
    int ypos;
    int slide;
    int dmode;
    int dchannels;
    int count;
    int frame_count;
    float *combine_buffer;
    AVFrame *in[101];
    int first;
    int nb_samples;
} AudioHistogramContext;
#define OFFSET(x) offsetof(AudioHistogramContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

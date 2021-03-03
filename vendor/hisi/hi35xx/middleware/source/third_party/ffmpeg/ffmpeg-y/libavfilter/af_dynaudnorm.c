#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#define FF_BUFQUEUE_SIZE 302
#include "libavfilter/bufferqueue.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
typedef struct cqueue {
    double *elements;
    int size;
    int nb_elements;
    int first;
} cqueue;
typedef struct DynamicAudioNormalizerContext {
    const AVClass *class;

    struct FFBufQueue queue;

    int frame_len;
    int frame_len_msec;
    int filter_size;
    int dc_correction;
    int channels_coupled;
    int alt_boundary_mode;

    double peak_value;
    double max_amplification;
    double target_rms;
    double compress_factor;
    double *prev_amplification_factor;
    double *dc_correction_value;
    double *compress_threshold;
    double *fade_factors[2];
    double *weights;

    int channels;
    int delay;
    int eof;
    int64_t pts;

    cqueue **gain_history_original;
    cqueue **gain_history_minimum;
    cqueue **gain_history_smoothed;

    cqueue *is_enabled;
} DynamicAudioNormalizerContext;
#define OFFSET(x) offsetof(DynamicAudioNormalizerContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
static void cqueue_free(cqueue *q)
{
    if (q)
        av_free(q->elements);
    av_free(q);
}

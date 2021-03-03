#include <rubberband/rubberband-c.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
typedef struct RubberBandContext {
    const AVClass *class;
    RubberBandState rbs;

    double tempo, pitch;
    int transients, detector, phase, window,
        smoothing, formant, opitch, channels;
    int64_t nb_samples_out;
    int64_t nb_samples_in;
    int64_t first_pts;
    int nb_samples;
} RubberBandContext;
#define OFFSET(x) offsetof(RubberBandContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

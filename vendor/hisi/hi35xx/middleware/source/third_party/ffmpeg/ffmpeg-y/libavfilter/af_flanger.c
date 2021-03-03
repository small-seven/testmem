#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
#include "generate_wave_table.h"
#define INTERPOLATION_LINEAR    0
#define INTERPOLATION_QUADRATIC 1
typedef struct FlangerContext {
    const AVClass *class;
    double delay_min;
    double delay_depth;
    double feedback_gain;
    double delay_gain;
    double speed;
    int wave_shape;
    double channel_phase;
    int interpolation;
    double in_gain;
    int max_samples;
    uint8_t **delay_buffer;
    int delay_buf_pos;
    double *delay_last;
    float *lfo;
    int lfo_length;
    int lfo_pos;
} FlangerContext;
#define OFFSET(x) offsetof(FlangerContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#include "ebur128.h"
typedef struct LoudNormContext {
    const AVClass *class;
    double target_i;
    double target_lra;
    double target_tp;
    double measured_i;
    double measured_lra;
    double measured_tp;
    double measured_thresh;
    double offset;
    int linear;
    int dual_mono;
    enum PrintFormat print_format;

    double *buf;
    int buf_size;
    int buf_index;
    int prev_buf_index;

    double delta[30];
    double weights[21];
    double prev_delta;
    int index;

    double gain_reduction[2];
    double *limiter_buf;
    double *prev_smp;
    int limiter_buf_index;
    int limiter_buf_size;
    enum LimiterState limiter_state;
    int peak_index;
    int env_index;
    int env_cnt;
    int attack_length;
    int release_length;

    int64_t pts;
    enum FrameType frame_type;
    int above_threshold;
    int prev_nb_samples;
    int channels;

    FFEBUR128State *r128_in;
    FFEBUR128State *r128_out;
} LoudNormContext;
#define OFFSET(x) offsetof(LoudNormContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

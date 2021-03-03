#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "formats.h"
#include "hermite.h"
typedef struct AudioGateContext {
    const AVClass *class;

    double level_in;
    double level_sc;
    double attack;
    double release;
    double threshold;
    double ratio;
    double knee;
    double makeup;
    double range;
    int link;
    int detection;
    int mode;

    double thres;
    double knee_start;
    double knee_stop;
    double lin_knee_start;
    double lin_knee_stop;
    double lin_slope;
    double attack_coeff;
    double release_coeff;

    AVAudioFifo *fifo[2];
    int64_t pts;
} AudioGateContext;
#define OFFSET(x) offsetof(AudioGateContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define FAKE_INFINITY (65536.0 * 65536.0)
#define IS_FAKE_INFINITY(value) (fabs(value-FAKE_INFINITY) < 1.0)
#if CONFIG_AGATE_FILTER
#define agate_options options
#endif /* CONFIG_AGATE_FILTER */
#if CONFIG_SIDECHAINGATE_FILTER
#define sidechaingate_options options
#endif  /* CONFIG_SIDECHAINGATE_FILTER */

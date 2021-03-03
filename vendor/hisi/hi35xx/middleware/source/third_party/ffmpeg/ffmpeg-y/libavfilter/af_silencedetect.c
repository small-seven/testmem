#include <float.h> /* DBL_MAX */
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "audio.h"
#include "formats.h"
#include "avfilter.h"
#include "internal.h"
typedef struct SilenceDetectContext {
    const AVClass *class;
    double noise;               ///< noise amplitude ratio
    double duration;            ///< minimum duration of silence until notification
    int mono;                   ///< mono mode : check each channel separately (default = check when ALL channels are silent)
    int channels;               ///< number of channels
    int independent_channels;   ///< number of entries in following arrays (always 1 in mono mode)
    int64_t *nb_null_samples;   ///< (array) current number of continuous zero samples
    int64_t *start;             ///< (array) if silence is detected, this value contains the time of the first zero sample (default/unset = INT64_MIN)
    int64_t frame_end;          ///< pts of the end of the current frame (used to compute duration of silence at EOS)
    int last_sample_rate;       ///< last sample rate to check for sample rate changes
    AVRational time_base;       ///< time_base

    void (*silencedetect)(struct SilenceDetectContext *s, AVFrame *insamples,
                          int nb_samples, int64_t nb_samples_notify,
                          AVRational time_base);
} SilenceDetectContext;
#define OFFSET(x) offsetof(SilenceDetectContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_AUDIO_PARAM
#define SILENCE_DETECT(name, type)                                               \

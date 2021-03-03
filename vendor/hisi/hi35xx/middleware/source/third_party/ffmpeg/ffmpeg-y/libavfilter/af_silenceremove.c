#include <float.h> /* DBL_MAX */
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "audio.h"
#include "formats.h"
#include "avfilter.h"
#include "internal.h"
typedef struct SilenceRemoveContext {
    const AVClass *class;

    enum SilenceMode mode;

    int start_periods;
    int64_t start_duration;
    int64_t start_duration_opt;
    double start_threshold;
    int64_t start_silence;
    int64_t start_silence_opt;
    int start_mode;

    int stop_periods;
    int64_t stop_duration;
    int64_t stop_duration_opt;
    double stop_threshold;
    int64_t stop_silence;
    int64_t stop_silence_opt;
    int stop_mode;

    double *start_holdoff;
    double *start_silence_hold;
    size_t start_holdoff_offset;
    size_t start_holdoff_end;
    size_t start_silence_offset;
    size_t start_silence_end;
    int    start_found_periods;

    double *stop_holdoff;
    double *stop_silence_hold;
    size_t stop_holdoff_offset;
    size_t stop_holdoff_end;
    size_t stop_silence_offset;
    size_t stop_silence_end;
    int    stop_found_periods;

    double window_ratio;
    double *window;
    double *window_current;
    double *window_end;
    int window_size;
    double sum;

    int restart;
    int64_t next_pts;

    int detection;
    void (*update)(struct SilenceRemoveContext *s, double sample);
    double(*compute)(struct SilenceRemoveContext *s, double sample);
} SilenceRemoveContext;
#define OFFSET(x) offsetof(SilenceRemoveContext, x)
#define AF AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_AUDIO_PARAM

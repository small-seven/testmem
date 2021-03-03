#include <float.h>
#include <math.h>
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#define MEASURE_ALL                     UINT_MAX
#define MEASURE_NONE                           0
#define MEASURE_DC_OFFSET               (1 <<  0)
#define MEASURE_MIN_LEVEL               (1 <<  1)
#define MEASURE_MAX_LEVEL               (1 <<  2)
#define MEASURE_MIN_DIFFERENCE          (1 <<  3)
#define MEASURE_MAX_DIFFERENCE          (1 <<  4)
#define MEASURE_MEAN_DIFFERENCE         (1 <<  5)
#define MEASURE_RMS_DIFFERENCE          (1 <<  6)
#define MEASURE_PEAK_LEVEL              (1 <<  7)
#define MEASURE_RMS_LEVEL               (1 <<  8)
#define MEASURE_RMS_PEAK                (1 <<  9)
#define MEASURE_RMS_TROUGH              (1 << 10)
#define MEASURE_CREST_FACTOR            (1 << 11)
#define MEASURE_FLAT_FACTOR             (1 << 12)
#define MEASURE_PEAK_COUNT              (1 << 13)
#define MEASURE_BIT_DEPTH               (1 << 14)
#define MEASURE_DYNAMIC_RANGE           (1 << 15)
#define MEASURE_ZERO_CROSSINGS          (1 << 16)
#define MEASURE_ZERO_CROSSINGS_RATE     (1 << 17)
#define MEASURE_NUMBER_OF_SAMPLES       (1 << 18)
#define MEASURE_NUMBER_OF_NANS          (1 << 19)
#define MEASURE_NUMBER_OF_INFS          (1 << 20)
#define MEASURE_NUMBER_OF_DENORMALS     (1 << 21)
#define MEASURE_MINMAXPEAK              (MEASURE_MIN_LEVEL | MEASURE_MAX_LEVEL | MEASURE_PEAK_LEVEL)
typedef struct ChannelStats {
    double last;
    double last_non_zero;
    double min_non_zero;
    double sigma_x, sigma_x2;
    double avg_sigma_x2, min_sigma_x2, max_sigma_x2;
    double min, max;
    double nmin, nmax;
    double min_run, max_run;
    double min_runs, max_runs;
    double min_diff, max_diff;
    double diff1_sum;
    double diff1_sum_x2;
    uint64_t mask, imask;
    uint64_t min_count, max_count;
    uint64_t zero_runs;
    uint64_t nb_samples;
    uint64_t nb_nans;
    uint64_t nb_infs;
    uint64_t nb_denormals;
} ChannelStats;
typedef struct AudioStatsContext {
    const AVClass *class;
    ChannelStats *chstats;
    int nb_channels;
    uint64_t tc_samples;
    double time_constant;
    double mult;
    int metadata;
    int reset_count;
    int nb_frames;
    int maxbitdepth;
    int measure_perchannel;
    int measure_overall;
    int is_float;
    int is_double;
} AudioStatsContext;
#define OFFSET(x) offsetof(AudioStatsContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define LINEAR_TO_DB(x) (log10(x) * 20)
#define UPDATE_STATS_P(type, update_func, update_float, channel_func)           \
#define UPDATE_STATS_I(type, update_func, update_float, channel_func)           \
#define UPDATE_STATS(planar, type, sample, normalizer_suffix, int_sample) \

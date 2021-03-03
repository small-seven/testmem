#include <float.h>
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ChannelStats {
    uint64_t nb_samples;
    uint64_t blknum;
    float peak;
    float sum;
    uint32_t peaks[10001];
    uint32_t rms[10001];
} ChannelStats;
typedef struct DRMeterContext {
    const AVClass *class;
    ChannelStats *chstats;
    int nb_channels;
    uint64_t tc_samples;
    double time_constant;
} DRMeterContext;
#define OFFSET(x) offsetof(DRMeterContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SQR(a) ((a)*(a))

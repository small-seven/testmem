#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libswresample/swresample.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct AResampleContext {
    const AVClass *class;
    int sample_rate_arg;
    double ratio;
    struct SwrContext *swr;
    int64_t next_pts;
    int more_data;
} AResampleContext;
#define OFFSET(x) offsetof(AResampleContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

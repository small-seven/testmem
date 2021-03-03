#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct APadContext {
    const AVClass *class;
    int64_t next_pts;

    int packet_size;
    int64_t pad_len, pad_len_left;
    int64_t whole_len, whole_len_left;
    int64_t pad_dur;
    int64_t whole_dur;
} APadContext;
#define OFFSET(x) offsetof(APadContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

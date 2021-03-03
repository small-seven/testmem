#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
typedef struct AudioPhaseMeterContext {
    const AVClass *class;
    AVFrame *out;
    int do_video;
    int w, h;
    AVRational frame_rate;
    int contrast[4];
    uint8_t *mpc_str;
    uint8_t mpc[4];
    int draw_median_phase;
} AudioPhaseMeterContext;
#define OFFSET(x) offsetof(AudioPhaseMeterContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

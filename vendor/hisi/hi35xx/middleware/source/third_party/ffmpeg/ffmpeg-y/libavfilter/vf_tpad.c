#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "internal.h"
#include "formats.h"
#include "drawutils.h"
typedef struct TPadContext {
    const AVClass *class;
    int pad_start;
    int pad_stop;
    int start_mode;
    int stop_mode;
    int64_t start_duration;
    int64_t stop_duration;
    uint8_t rgba_color[4];  ///< color for the padding area

    FFDrawContext draw;
    FFDrawColor color;
    int64_t pts;
    int eof;
    AVFrame *cache_start;
    AVFrame *cache_stop;
} TPadContext;
#define OFFSET(x) offsetof(TPadContext, x)
#define VF AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

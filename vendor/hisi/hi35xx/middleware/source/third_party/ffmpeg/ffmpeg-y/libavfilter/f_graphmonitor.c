#include "float.h"
#include "libavutil/pixdesc.h"
#include "libavutil/eval.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct GraphMonitorContext {
    const AVClass *class;

    int w, h;
    float opacity;
    int mode;
    int flags;
    AVRational frame_rate;

    int64_t pts;
    uint8_t white[4];
    uint8_t yellow[4];
    uint8_t red[4];
    uint8_t green[4];
    uint8_t bg[4];
} GraphMonitorContext;
#define OFFSET(x) offsetof(GraphMonitorContext, x)
#define VF AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_GRAPHMONITOR_FILTER
#endif // CONFIG_GRAPHMONITOR_FILTER
#if CONFIG_AGRAPHMONITOR_FILTER
#define agraphmonitor_options graphmonitor_options
#endif // CONFIG_AGRAPHMONITOR_FILTER

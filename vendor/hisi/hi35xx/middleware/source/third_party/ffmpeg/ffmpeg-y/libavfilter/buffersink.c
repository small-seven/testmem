#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#define FF_INTERNAL_FIELDS 1
#include "framequeue.h"
#include "audio.h"
#include "avfilter.h"
#include "buffersink.h"
#include "filters.h"
#include "internal.h"
typedef struct BufferSinkContext {
    const AVClass *class;
    unsigned warning_limit;

    /* only used for video */
    enum AVPixelFormat *pixel_fmts;           ///< list of accepted pixel formats, must be terminated with -1
    int pixel_fmts_size;

    /* only used for audio */
    enum AVSampleFormat *sample_fmts;       ///< list of accepted sample formats, terminated by AV_SAMPLE_FMT_NONE
    int sample_fmts_size;
    int64_t *channel_layouts;               ///< list of accepted channel layouts, terminated by -1
    int channel_layouts_size;
    int *channel_counts;                    ///< list of accepted channel counts, terminated by -1
    int channel_counts_size;
    int all_channel_counts;
    int *sample_rates;                      ///< list of accepted sample rates, terminated by -1
    int sample_rates_size;

    AVFrame *peeked_frame;
} BufferSinkContext;
#define NB_ITEMS(list) (list ## _size / sizeof(*list))
#define FIFO_INIT_SIZE 8
#define FIFO_INIT_ELEMENT_SIZE sizeof(void *)
#define MAKE_AVFILTERLINK_ACCESSOR(type, field) \
#define CHECK_LIST_SIZE(field) \
#define OFFSET(x) offsetof(BufferSinkContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#undef FLAGS
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_AUDIO_PARAM
#undef FLAGS

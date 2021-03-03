#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct AFormatContext {
    const AVClass   *class;

    AVFilterFormats *formats;
    AVFilterFormats *sample_rates;
    AVFilterChannelLayouts *channel_layouts;

    char *formats_str;
    char *sample_rates_str;
    char *channel_layouts_str;
} AFormatContext;
#define OFFSET(x) offsetof(AFormatContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define PARSE_FORMATS(str, type, list, add_to_list, unref_fn, get_fmt, none, desc)    \

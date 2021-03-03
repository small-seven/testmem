#include "libavutil/attributes.h"
#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct ChannelSplitContext {
    const AVClass *class;

    uint64_t channel_layout;
    char    *channel_layout_str;
    char    *channels_str;

    int      map[64];
} ChannelSplitContext;
#define OFFSET(x) offsetof(ChannelSplitContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM

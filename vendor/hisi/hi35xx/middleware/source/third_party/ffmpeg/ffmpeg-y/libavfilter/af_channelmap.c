#include <ctype.h>
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define MAX_CH 64
typedef struct ChannelMapContext {
    const AVClass *class;
    char *mapping_str;
    char *channel_layout_str;
    uint64_t output_layout;
    struct ChannelMap map[MAX_CH];
    int nch;
    enum MappingMode mode;
} ChannelMapContext;
#define OFFSET(x) offsetof(ChannelMapContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM

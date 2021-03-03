#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
typedef struct AudioBitScopeContext {
    const AVClass *class;
    int w, h;
    AVRational frame_rate;
    char *colors;

    int nb_channels;
    int nb_samples;
    int depth;
    uint8_t *fg;

    uint64_t counter[64];
} AudioBitScopeContext;
#define OFFSET(x) offsetof(AudioBitScopeContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

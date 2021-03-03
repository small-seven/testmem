#include <stdio.h>
#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct SplitContext {
    const AVClass *class;
    int nb_outputs;
} SplitContext;
#define OFFSET(x) offsetof(SplitContext, x)
#define FLAGS (AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
#define split_options options
#define asplit_options options

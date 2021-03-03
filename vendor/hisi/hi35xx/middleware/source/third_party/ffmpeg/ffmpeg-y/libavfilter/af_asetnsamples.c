#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "internal.h"
#include "formats.h"
typedef struct ASNSContext {
    const AVClass *class;
    int nb_out_samples;  ///< how many samples to output
    int pad;
} ASNSContext;
#define OFFSET(x) offsetof(ASNSContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

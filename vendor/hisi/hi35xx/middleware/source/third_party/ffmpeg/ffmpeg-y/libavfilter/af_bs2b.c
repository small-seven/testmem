#include <bs2b.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef void (*filter_func)(t_bs2bdp bs2bdp, uint8_t *sample, int n);

typedef struct Bs2bContext {
    const AVClass *class;

    int profile;
    int fcut;
    int feed;

    t_bs2bdp bs2bp;

    filter_func filter;
} Bs2bContext;
#define OFFSET(x) offsetof(Bs2bContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libswresample/swresample.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define MAX_CHANNELS 64
typedef struct PanContext {
    const AVClass *class;
    char *args;
    int64_t out_channel_layout;
    double gain[MAX_CHANNELS][MAX_CHANNELS];
    int64_t need_renorm;
    int need_renumber;
    int nb_output_channels;

    int pure_gains;
    /* channel mapping specific */
    int channel_map[MAX_CHANNELS];
    struct SwrContext *swr;
} PanContext;
#define OFFSET(x) offsetof(PanContext, x)

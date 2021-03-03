#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct AudioContrastContext {
    const AVClass *class;
    float contrast;
    void (*filter)(void **dst, const void **src,
                   int nb_samples, int channels, float contrast);
} AudioContrastContext;
#define OFFSET(x) offsetof(AudioContrastContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

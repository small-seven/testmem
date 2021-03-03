#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct CrystalizerContext {
    const AVClass *class;
    float mult;
    int clip;
    AVFrame *prev;
    void (*filter)(void **dst, void **prv, const void **src,
                   int nb_samples, int channels, float mult, int clip);
} CrystalizerContext;
#define OFFSET(x) offsetof(CrystalizerContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

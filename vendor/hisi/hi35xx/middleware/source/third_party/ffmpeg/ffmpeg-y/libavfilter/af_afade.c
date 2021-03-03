#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
typedef struct AudioFadeContext {
    const AVClass *class;
    int type;
    int curve, curve2;
    int64_t nb_samples;
    int64_t start_sample;
    int64_t duration;
    int64_t start_time;
    int overlap;
    int cf0_eof;
    int crossfade_is_over;
    int64_t pts;

    void (*fade_samples)(uint8_t **dst, uint8_t * const *src,
                         int nb_samples, int channels, int direction,
                         int64_t start, int64_t range, int curve);
    void (*crossfade_samples)(uint8_t **dst, uint8_t * const *cf0,
                              uint8_t * const *cf1,
                              int nb_samples, int channels,
                              int curve0, int curve1);
} AudioFadeContext;
#define OFFSET(x) offsetof(AudioFadeContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CUBE(a) ((a)*(a)*(a))
#define FADE_PLANAR(name, type)                                             \
#define FADE(name, type)                                                    \
#if CONFIG_AFADE_FILTER
#endif /* CONFIG_AFADE_FILTER */
#if CONFIG_ACROSSFADE_FILTER
#define CROSSFADE_PLANAR(name, type)                                           \
#define CROSSFADE(name, type)                                               \
#endif /* CONFIG_ACROSSFADE_FILTER */

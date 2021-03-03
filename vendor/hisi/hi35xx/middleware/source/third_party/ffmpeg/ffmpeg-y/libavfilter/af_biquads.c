#include "libavutil/avassert.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ChanCache {
    double i1, i2;
    double o1, o2;
    int clippings;
} ChanCache;
typedef struct BiquadsContext {
    const AVClass *class;

    enum FilterType filter_type;
    int width_type;
    int poles;
    int csg;

    double gain;
    double frequency;
    double width;
    double mix;
    uint64_t channels;

    double a0, a1, a2;
    double b0, b1, b2;

    ChanCache *cache;
    int block_align;

    void (*filter)(struct BiquadsContext *s, const void *ibuf, void *obuf, int len,
                   double *i1, double *i2, double *o1, double *o2,
                   double b0, double b1, double b2, double a1, double a2, int *clippings,
                   int disabled);
} BiquadsContext;
#define BIQUAD_FILTER(name, type, min, max, need_clipping)                    \
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#define OFFSET(x) offsetof(BiquadsContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define DEFINE_BIQUAD_FILTER(name_, description_)                       \
#if CONFIG_EQUALIZER_FILTER
#endif  /* CONFIG_EQUALIZER_FILTER */
#if CONFIG_BASS_FILTER
#endif  /* CONFIG_BASS_FILTER */
#if CONFIG_TREBLE_FILTER
#endif  /* CONFIG_TREBLE_FILTER */
#if CONFIG_BANDPASS_FILTER
#endif  /* CONFIG_BANDPASS_FILTER */
#if CONFIG_BANDREJECT_FILTER
#endif  /* CONFIG_BANDREJECT_FILTER */
#if CONFIG_LOWPASS_FILTER
#endif  /* CONFIG_LOWPASS_FILTER */
#if CONFIG_HIGHPASS_FILTER
#endif  /* CONFIG_HIGHPASS_FILTER */
#if CONFIG_ALLPASS_FILTER
#endif  /* CONFIG_ALLPASS_FILTER */
#if CONFIG_LOWSHELF_FILTER
#endif  /* CONFIG_LOWSHELF_FILTER */
#if CONFIG_HIGHSHELF_FILTER
#endif  /* CONFIG_HIGHSHELF_FILTER */
#if CONFIG_BIQUAD_FILTER
#endif  /* CONFIG_BIQUAD_FILTER */

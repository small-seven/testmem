#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct ASoftClipContext {
    const AVClass *class;

    int type;
    double param;

    void (*filter)(struct ASoftClipContext *s, void **dst, const void **src,
                   int nb_samples, int channels);
} ASoftClipContext;
#define OFFSET(x) offsetof(ASoftClipContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SQR(x) ((x) * (x))

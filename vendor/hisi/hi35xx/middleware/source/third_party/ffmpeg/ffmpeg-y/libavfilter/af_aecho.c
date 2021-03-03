#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct AudioEchoContext {
    const AVClass *class;
    float in_gain, out_gain;
    char *delays, *decays;
    float *delay, *decay;
    int nb_echoes;
    int delay_index;
    uint8_t **delayptrs;
    int max_samples, fade_out;
    int *samples;
    int64_t next_pts;

    void (*echo_samples)(struct AudioEchoContext *ctx, uint8_t **delayptrs,
                         uint8_t * const *src, uint8_t **dst,
                         int nb_samples, int channels);
} AudioEchoContext;
#define OFFSET(x) offsetof(AudioEchoContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define MOD(a, b) (((a) >= (b)) ? (a) - (b) : (a))
#define ECHO(name, type, min, max)                                          \

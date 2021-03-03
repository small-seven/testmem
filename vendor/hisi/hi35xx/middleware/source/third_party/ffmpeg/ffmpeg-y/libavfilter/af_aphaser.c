#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "generate_wave_table.h"
typedef struct AudioPhaserContext {
    const AVClass *class;
    double in_gain, out_gain;
    double delay;
    double decay;
    double speed;

    int type;

    int delay_buffer_length;
    double *delay_buffer;

    int modulation_buffer_length;
    int32_t *modulation_buffer;

    int delay_pos, modulation_pos;

    void (*phaser)(struct AudioPhaserContext *s,
                   uint8_t * const *src, uint8_t **dst,
                   int nb_samples, int channels);
} AudioPhaserContext;
#define OFFSET(x) offsetof(AudioPhaserContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define MOD(a, b) (((a) >= (b)) ? (a) - (b) : (a))
#define PHASER_PLANAR(name, type)                                      \
#define PHASER(name, type)                                              \

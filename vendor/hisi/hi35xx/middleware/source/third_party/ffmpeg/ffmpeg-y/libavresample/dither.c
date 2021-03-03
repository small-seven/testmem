#include <math.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/lfg.h"
#include "libavutil/mem.h"
#include "libavutil/samplefmt.h"
#include "audio_convert.h"
#include "dither.h"
#include "internal.h"
typedef struct DitherState {
    int mute;
    unsigned int seed;
    AVLFG lfg;
    float *noise_buf;
    int noise_buf_size;
    int noise_buf_ptr;
    float dither_a[4];
    float dither_b[4];
} DitherState;
#define MUTE_THRESHOLD_SEC 0.000333
#define S16_SCALE 32753.0f
#define LFG_SCALE (1.0f / (2.0f * INT32_MAX))
#define SQRT_1_6 0.40824829046386301723f
void ff_dither_free(DitherContext **cp)
{
    DitherContext *c = *cp;
    int ch;

    if (!c)
        return;
    ff_audio_data_free(&c->flt_data);
    ff_audio_data_free(&c->s16_data);
    ff_audio_convert_free(&c->ac_in);
    ff_audio_convert_free(&c->ac_out);
    for (ch = 0; ch < c->channels; ch++)
        av_free(c->state[ch].noise_buf);
    av_free(c->state);
    av_freep(cp);
}

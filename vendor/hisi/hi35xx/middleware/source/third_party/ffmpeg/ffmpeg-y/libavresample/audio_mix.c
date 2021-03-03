#include <stdint.h>
#include "libavutil/common.h"
#include "libavutil/libm.h"
#include "libavutil/samplefmt.h"
#include "avresample.h"
#include "internal.h"
#include "audio_data.h"
#include "audio_mix.h"
#define MIX_FUNC_NAME(fmt, cfmt) mix_any_ ## fmt ##_## cfmt ##_c
#define MIX_FUNC_GENERIC(fmt, cfmt, stype, ctype, sumtype, expr)            \
void ff_audio_mix_free(AudioMix **am_p)
{
    AudioMix *am;

    if (!*am_p)
        return;
    am = *am_p;

    if (am->matrix) {
        av_free(am->matrix[0]);
        am->matrix = NULL;
    }
    memset(am->matrix_q8,  0, sizeof(am->matrix_q8 ));
    memset(am->matrix_q15, 0, sizeof(am->matrix_q15));
    memset(am->matrix_flt, 0, sizeof(am->matrix_flt));

    av_freep(am_p);
}
#define GET_MATRIX_CONVERT(suffix, scale)                                   \
#define CONVERT_MATRIX(type, expr)                                          \

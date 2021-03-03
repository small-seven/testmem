#include "libavutil/avstring.h"
#include "libavutil/avassert.h"
#include "libavutil/libm.h"
#include "libavutil/samplefmt.h"
#include "audioconvert.h"
#define CONV_FUNC_NAME(dst_fmt, src_fmt) conv_ ## src_fmt ## _to_ ## dst_fmt
#define CONV_FUNC(ofmt, otype, ifmt, expr)\
#define FMT_PAIR_FUNC(out, in) [(out) + AV_SAMPLE_FMT_NB*(in)] = CONV_FUNC_NAME(out, in)
void swri_audio_convert_free(AudioConvert **ctx)
{
    av_freep(ctx);
}

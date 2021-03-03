#include <stdint.h>
#include "config.h"
#include "libavutil/common.h"
#include "libavutil/libm.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/samplefmt.h"
#include "audio_convert.h"
#include "audio_data.h"
#include "dither.h"
typedef void (conv_func_flat)(uint8_t *out, const uint8_t *in, int len);

typedef void (conv_func_interleave)(uint8_t *out, uint8_t *const *in,
                                    int len, int channels);

typedef void (conv_func_deinterleave)(uint8_t **out, const uint8_t *in, int len,
                                      int channels);

struct AudioConvert {
    AVAudioResampleContext *avr;
    DitherContext *dc;
    enum AVSampleFormat in_fmt;
    enum AVSampleFormat out_fmt;
    int apply_map;
    int channels;
    int planes;
    int ptr_align;
    int samples_align;
    int has_optimized_func;
    const char *func_descr;
    const char *func_descr_generic;
    enum ConvFuncType func_type;
    conv_func_flat         *conv_flat;
    conv_func_flat         *conv_flat_generic;
    conv_func_interleave   *conv_interleave;
    conv_func_interleave   *conv_interleave_generic;
    conv_func_deinterleave *conv_deinterleave;
    conv_func_deinterleave *conv_deinterleave_generic;
};
#define CONV_FUNC_NAME(dst_fmt, src_fmt) conv_ ## src_fmt ## _to_ ## dst_fmt
#define CONV_LOOP(otype, expr)                                              \
#define CONV_FUNC_FLAT(ofmt, otype, ifmt, itype, expr)                      \
#define CONV_FUNC_INTERLEAVE(ofmt, otype, ifmt, itype, expr)                \
#define CONV_FUNC_DEINTERLEAVE(ofmt, otype, ifmt, itype, expr)              \
#define CONV_FUNC_GROUP(ofmt, otype, ifmt, itype, expr) \
#define SET_CONV_FUNC_GROUP(ofmt, ifmt)                                                             \
void ff_audio_convert_free(AudioConvert **ac)
{
    if (!*ac)
        return;
    ff_dither_free(&(*ac)->dc);
    av_freep(ac);
}

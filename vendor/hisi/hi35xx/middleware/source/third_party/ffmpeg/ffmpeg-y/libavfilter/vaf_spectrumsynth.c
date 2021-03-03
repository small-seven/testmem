#include "libavcodec/avfft.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avfilter.h"
#include "formats.h"
#include "audio.h"
#include "video.h"
#include "internal.h"
#include "window_func.h"
typedef struct SpectrumSynthContext {
    const AVClass *class;
    int sample_rate;
    int channels;
    int scale;
    int sliding;
    int win_func;
    float overlap;
    int orientation;

    AVFrame *magnitude, *phase;
    FFTContext *fft;            ///< Fast Fourier Transform context
    int fft_bits;               ///< number of bits (FFT window size = 1<<fft_bits)
    FFTComplex **fft_data;      ///< bins holder for each (displayed) channels
    int win_size;
    int size;
    int nb_freq;
    int hop_size;
    int start, end;
    int xpos;
    int xend;
    int64_t pts;
    float factor;
    AVFrame *buffer;
    float *window_func_lut;     ///< Window function LUT
} SpectrumSynthContext;
#define OFFSET(x) offsetof(SpectrumSynthContext, x)
#define A AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_AUDIO_PARAM
#define V AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

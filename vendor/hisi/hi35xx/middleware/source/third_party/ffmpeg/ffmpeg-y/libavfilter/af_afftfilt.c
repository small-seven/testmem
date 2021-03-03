#include "libavutil/audio_fifo.h"
#include "libavutil/avstring.h"
#include "libavfilter/internal.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libavutil/eval.h"
#include "audio.h"
#include "filters.h"
#include "window_func.h"
typedef struct AFFTFiltContext {
    const AVClass *class;
    char *real_str;
    char *img_str;
    int fft_size;
    int fft_bits;

    FFTContext *fft, *ifft;
    FFTComplex **fft_data;
    FFTComplex **fft_temp;
    int nb_exprs;
    int window_size;
    AVExpr **real;
    AVExpr **imag;
    AVAudioFifo *fifo;
    int64_t pts;
    int hop_size;
    float overlap;
    AVFrame *buffer;
    int eof;
    int win_func;
    float *window_func_lut;
} AFFTFiltContext;
#define OFFSET(x) offsetof(AFFTFiltContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

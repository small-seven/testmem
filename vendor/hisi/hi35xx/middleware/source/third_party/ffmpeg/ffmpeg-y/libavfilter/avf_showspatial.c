#include <float.h>
#include <math.h>
#include "libavcodec/avfft.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "audio.h"
#include "video.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#include "window_func.h"
typedef struct ShowSpatialContext {
    const AVClass *class;
    int w, h;
    AVRational frame_rate;
    FFTContext *fft[2];           ///< Fast Fourier Transform context
    FFTContext *ifft[2];          ///< Inverse Fast Fourier Transform context
    int fft_bits;                 ///< number of bits (FFT window size = 1<<fft_bits)
    FFTComplex *fft_data[2];      ///< bins holder for each (displayed) channels
    float *window_func_lut;       ///< Window function LUT
    int win_func;
    int win_size;
    int buf_size;
    float overlap;
    int consumed;
    int hop_size;
    AVAudioFifo *fifo;
    int64_t pts;
} ShowSpatialContext;
#define OFFSET(x) offsetof(ShowSpatialContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define RE(y, ch) s->fft_data[ch][y].re
#define IM(y, ch) s->fft_data[ch][y].im

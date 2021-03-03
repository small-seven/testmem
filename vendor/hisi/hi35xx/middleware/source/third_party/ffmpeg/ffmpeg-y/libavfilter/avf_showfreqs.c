#include <float.h>
#include <math.h>
#include "libavcodec/avfft.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "audio.h"
#include "filters.h"
#include "video.h"
#include "avfilter.h"
#include "internal.h"
#include "window_func.h"
typedef struct ShowFreqsContext {
    const AVClass *class;
    int w, h;
    int mode;
    int cmode;
    int fft_size;
    int fft_bits;
    int ascale, fscale;
    int avg;
    int win_func;
    FFTContext *fft;
    FFTComplex **fft_data;
    float **avg_data;
    float *window_func_lut;
    float overlap;
    float minamp;
    int hop_size;
    int nb_channels;
    int nb_freq;
    int win_size;
    float scale;
    char *colors;
    AVAudioFifo *fifo;
    int64_t pts;
} ShowFreqsContext;
#define OFFSET(x) offsetof(ShowFreqsContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define RE(x, ch) s->fft_data[ch][x].re
#define IM(x, ch) s->fft_data[ch][x].im
#define M(a, b) (sqrt((a) * (a) + (b) * (b)))

#include <math.h>
#include "libavcodec/avfft.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/xga_font_data.h"
#include "audio.h"
#include "video.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#include "window_func.h"
typedef struct ShowSpectrumContext {
    const AVClass *class;
    int w, h;
    char *rate_str;
    AVRational auto_frame_rate;
    AVRational frame_rate;
    AVFrame *outpicref;
    int nb_display_channels;
    int orientation;
    int channel_width;
    int channel_height;
    int sliding;                ///< 1 if sliding mode, 0 otherwise
    int mode;                   ///< channel display mode
    int color_mode;             ///< display color scheme
    int scale;
    int fscale;
    float saturation;           ///< color saturation multiplier
    float rotation;             ///< color rotation
    int start, stop;            ///< zoom mode
    int data;
    int xpos;                   ///< x position (current column)
    FFTContext **fft;           ///< Fast Fourier Transform context
    FFTContext **ifft;          ///< Inverse Fast Fourier Transform context
    int fft_bits;               ///< number of bits (FFT window size = 1<<fft_bits)
    FFTComplex **fft_data;      ///< bins holder for each (displayed) channels
    FFTComplex **fft_scratch;   ///< scratch buffers
    float *window_func_lut;     ///< Window function LUT
    float **magnitudes;
    float **phases;
    int win_func;
    int win_size;
    int buf_size;
    double win_scale;
    float overlap;
    float gain;
    int consumed;
    int hop_size;
    float *combine_buffer;      ///< color combining buffer (3 * h items)
    float **color_buffer;       ///< color buffer (3 * h * ch items)
    AVAudioFifo *fifo;
    int64_t pts;
    int64_t old_pts;
    int old_len;
    int single_pic;
    int legend;
    int start_x, start_y;
    int (*plot_channel)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ShowSpectrumContext;
#define OFFSET(x) offsetof(ShowSpectrumContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define RE(y, ch) s->fft_data[ch][y].re
#define IM(y, ch) s->fft_data[ch][y].im
#define MAGNITUDE(y, ch) hypotf(RE(y, ch), IM(y, ch))
#define PHASE(y, ch) atan2f(IM(y, ch), RE(y, ch))
#if CONFIG_SHOWSPECTRUM_FILTER
#endif // CONFIG_SHOWSPECTRUM_FILTER
#if CONFIG_SHOWSPECTRUMPIC_FILTER
#endif // CONFIG_SHOWSPECTRUMPIC_FILTER

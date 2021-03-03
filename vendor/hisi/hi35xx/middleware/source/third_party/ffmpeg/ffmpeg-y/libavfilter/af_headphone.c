#include <math.h>
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/intmath.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#include "audio.h"
#define TIME_DOMAIN      0
#define FREQUENCY_DOMAIN 1
#define HRIR_STEREO 0
#define HRIR_MULTI  1
typedef struct HeadphoneContext {
    const AVClass *class;

    char *map;
    int type;

    int lfe_channel;

    int have_hrirs;
    int eof_hrirs;

    int ir_len;
    int air_len;

    int mapping[64];

    int nb_inputs;

    int nb_irs;

    float gain;
    float lfe_gain, gain_lfe;

    float *ringbuffer[2];
    int write[2];

    int buffer_length;
    int n_fft;
    int size;
    int hrir_fmt;

    int *delay[2];
    float *data_ir[2];
    float *temp_src[2];
    FFTComplex *temp_fft[2];
    FFTComplex *temp_afft[2];

    FFTContext *fft[2], *ifft[2];
    FFTComplex *data_hrtf[2];

    AVFloatDSPContext *fdsp;
    struct headphone_inputs {
        AVFrame     *frame;
        int          ir_len;
        int          delay_l;
        int          delay_r;
        int          eof;
    } *in;
typedef struct ThreadData {
    AVFrame *in, *out;
    int *write;
    int **delay;
    float **ir;
    int *n_clippings;
    float **ringbuffer;
    float **temp_src;
    FFTComplex **temp_fft;
    FFTComplex **temp_afft;
} ThreadData;
#define OFFSET(x) offsetof(HeadphoneContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

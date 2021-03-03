#include <float.h>
#include "libavutil/audio_fifo.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "filters.h"
#define C       (M_LN10 * 0.1)
#define RATIO    0.98
#define RRATIO  (1.0 - RATIO)
typedef struct DeNoiseChannel {
    int         band_noise[15];
    double      noise_band_auto_var[15];
    double      noise_band_sample[15];
    double     *amt;
    double     *band_amt;
    double     *band_excit;
    double     *gain;
    double     *prior;
    double     *prior_band_excit;
    double     *clean_data;
    double     *noisy_data;
    double     *out_samples;
    double     *spread_function;
    double     *abs_var;
    double     *rel_var;
    double     *min_abs_var;
    FFTComplex *fft_data;
    FFTContext *fft, *ifft;

    double      noise_band_norm[15];
    double      noise_band_avr[15];
    double      noise_band_avi[15];
    double      noise_band_var[15];

    double      sfm_threshold;
    double      sfm_alpha;
    double      sfm_results[3];
    int         sfm_fail_flags[512];
    int         sfm_fail_total;
} DeNoiseChannel;
typedef struct AudioFFTDeNoiseContext {
    const AVClass *class;

    float   noise_reduction;
    float   noise_floor;
    int     noise_type;
    char   *band_noise_str;
    float   residual_floor;
    int     track_noise;
    int     track_residual;
    int     output_mode;

    float   last_residual_floor;
    float   last_noise_floor;
    float   last_noise_reduction;
    float   last_noise_balance;
    int64_t block_count;

    int64_t pts;
    int     channels;
    int     sample_noise;
    int     sample_noise_start;
    int     sample_noise_end;
    float   sample_rate;
    int     buffer_length;
    int     fft_length;
    int     fft_length2;
    int     bin_count;
    int     window_length;
    int     sample_advance;
    int     number_of_bands;

    int     band_centre[15];

    int    *bin2band;
    double *window;
    double *band_alpha;
    double *band_beta;

    DeNoiseChannel *dnch;

    double  max_gain;
    double  max_var;
    double  gain_scale;
    double  window_weight;
    double  floor;
    double  sample_floor;
    double  auto_floor;

    int     noise_band_edge[17];
    int     noise_band_count;
    double  matrix_a[25];
    double  vector_b[5];
    double  matrix_b[75];
    double  matrix_c[75];

    AVAudioFifo *fifo;
} AudioFFTDeNoiseContext;
#define OFFSET(x) offsetof(AudioFFTDeNoiseContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    AVFrame *in;
} ThreadData;

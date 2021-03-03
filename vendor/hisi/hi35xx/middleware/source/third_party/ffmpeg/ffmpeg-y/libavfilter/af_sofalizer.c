#include <math.h>
#include <mysofa.h>
#include "libavcodec/avfft.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/intmath.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#include "audio.h"
#define TIME_DOMAIN      0
#define FREQUENCY_DOMAIN 1
typedef struct MySofa {  /* contains data of one SOFA file */
    struct MYSOFA_HRTF *hrtf;
    struct MYSOFA_LOOKUP *lookup;
    struct MYSOFA_NEIGHBORHOOD *neighborhood;
    int ir_samples;      /* length of one impulse response (IR) */
    int n_samples;       /* ir_samples to next power of 2 */
    float *lir, *rir;    /* IRs (time-domain) */
    float *fir;
    int max_delay;
} MySofa;
typedef struct VirtualSpeaker {
    uint8_t set;
    float azim;
    float elev;
} VirtualSpeaker;
typedef struct SOFAlizerContext {
    const AVClass *class;

    char *filename;             /* name of SOFA file */
    MySofa sofa;                /* contains data of the SOFA file */

    int sample_rate;            /* sample rate from SOFA file */
    float *speaker_azim;        /* azimuth of the virtual loudspeakers */
    float *speaker_elev;        /* elevation of the virtual loudspeakers */
    char *speakers_pos;         /* custom positions of the virtual loudspeakers */
    float lfe_gain;             /* initial gain for the LFE channel */
    float gain_lfe;             /* gain applied to LFE channel */
    int lfe_channel;            /* LFE channel position in channel layout */

    int n_conv;                 /* number of channels to convolute */

                                /* buffer variables (for convolution) */
    float *ringbuffer[2];       /* buffers input samples, length of one buffer: */
                                /* no. input ch. (incl. LFE) x buffer_length */
    int write[2];               /* current write position to ringbuffer */
    int buffer_length;          /* is: longest IR plus max. delay in all SOFA files */
                                /* then choose next power of 2 */
    int n_fft;                  /* number of samples in one FFT block */
    int nb_samples;

                                /* netCDF variables */
    int *delay[2];              /* broadband delay for each channel/IR to be convolved */

    float *data_ir[2];          /* IRs for all channels to be convolved */
                                /* (this excludes the LFE) */
    float *temp_src[2];
    FFTComplex *temp_fft[2];    /* Array to hold FFT values */
    FFTComplex *temp_afft[2];   /* Array to accumulate FFT values prior to IFFT */

                         /* control variables */
    float gain;          /* filter gain (in dB) */
    float rotation;      /* rotation of virtual loudspeakers (in degrees)  */
    float elevation;     /* elevation of virtual loudspeakers (in deg.) */
    float radius;        /* distance virtual loudspeakers to listener (in metres) */
    int type;            /* processing type */
    int framesize;       /* size of buffer */
    int normalize;       /* should all IRs be normalized upon import ? */
    int interpolate;     /* should wanted IRs be interpolated from neighbors ? */
    int minphase;        /* should all IRs be minphased upon import ? */
    float anglestep;     /* neighbor search angle step, in agles */
    float radstep;       /* neighbor search radius step, in meters */

    VirtualSpeaker vspkrpos[64];

    FFTContext *fft[2], *ifft[2];
    FFTComplex *data_hrtf[2];

    AVFloatDSPContext *fdsp;
} SOFAlizerContext;
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
#define OFFSET(x) offsetof(SOFAlizerContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

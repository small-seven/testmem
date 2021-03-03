#include "libavutil/audio_fifo.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
typedef struct DeclickChannel {
    double *auxiliary;
    double *detection;
    double *acoefficients;
    double *acorrelation;
    double *tmp;
    double *interpolated;
    double *matrix;
    int matrix_size;
    double *vector;
    int vector_size;
    double *y;
    int y_size;
    uint8_t *click;
    int *index;
    unsigned *histogram;
    int histogram_size;
} DeclickChannel;
typedef struct AudioDeclickContext {
    const AVClass *class;

    double w;
    double overlap;
    double threshold;
    double ar;
    double burst;
    int method;
    int nb_hbins;

    int is_declip;
    int ar_order;
    int nb_burst_samples;
    int window_size;
    int hop_size;
    int overlap_skip;

    AVFrame *in;
    AVFrame *out;
    AVFrame *buffer;
    AVFrame *is;

    DeclickChannel *chan;

    int64_t pts;
    int nb_channels;
    uint64_t nb_samples;
    uint64_t detected_errors;
    int samples_left;
    int eof;

    AVAudioFifo *fifo;
    double *window_func_lut;

    int (*detector)(struct AudioDeclickContext *s, DeclickChannel *c,
                    double sigmae, double *detection,
                    double *acoefficients, uint8_t *click, int *index,
                    const double *src, double *dst);
} AudioDeclickContext;
#define OFFSET(x) offsetof(AudioDeclickContext, x)
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    AVFrame *out;
} ThreadData;

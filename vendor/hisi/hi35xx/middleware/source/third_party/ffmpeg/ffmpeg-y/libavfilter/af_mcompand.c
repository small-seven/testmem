#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct CompandSegment {
    double x, y;
    double a, b;
} CompandSegment;
typedef struct CompandT {
    CompandSegment *segments;
    int nb_segments;
    double in_min_lin;
    double out_min_lin;
    double curve_dB;
    double gain_dB;
} CompandT;
#define N 4
typedef struct PrevCrossover {
    double in;
    double out_low;
    double out_high;
} PrevCrossover[N * 2];
typedef struct Crossover {
  PrevCrossover *previous;
  size_t         pos;
  double         coefs[3 *(N+1)];
} Crossover;
typedef struct CompBand {
    CompandT transfer_fn;
    double *attack_rate;
    double *decay_rate;
    double *volume;
    double delay;
    double topfreq;
    Crossover filter;
    AVFrame *delay_buf;
    size_t delay_size;
    ptrdiff_t delay_buf_ptr;
    size_t delay_buf_cnt;
} CompBand;
typedef struct MCompandContext {
    const AVClass *class;

    char *args;

    int nb_bands;
    CompBand *bands;
    AVFrame *band_buf1, *band_buf2, *band_buf3;
    int band_samples;
    size_t delay_buf_size;
} MCompandContext;
#define OFFSET(x) offsetof(MCompandContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define S(x) s->segments[2 * ((x) + 1)]
#undef S
#define S(x) s->segments[2 * (x)]
#define L(x) s->segments[i - (x)]
#define CONVOLVE _ _ _ _
#define _ out_low += p->coefs[j] * p->previous[ch][p->pos + j].in \
#undef _
#define _ out_high += p->coefs[j+N+1] * p->previous[ch][p->pos + j].in \

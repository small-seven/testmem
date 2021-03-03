#include "libavutil/opt.h"
#include "libavutil/eval.h"
#include "libavutil/avassert.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#define RDFT_BITS_MIN 4
#define RDFT_BITS_MAX 16
#define NB_GAIN_ENTRY_MAX 4096
typedef struct GainEntry {
    double  freq;
    double  gain;
} GainEntry;
typedef struct OverlapIndex {
    int buf_idx;
    int overlap_idx;
} OverlapIndex;
typedef struct FIREqualizerContext {
    const AVClass *class;

    RDFTContext   *analysis_rdft;
    RDFTContext   *analysis_irdft;
    RDFTContext   *rdft;
    RDFTContext   *irdft;
    FFTContext    *fft_ctx;
    RDFTContext   *cepstrum_rdft;
    RDFTContext   *cepstrum_irdft;
    int           analysis_rdft_len;
    int           rdft_len;
    int           cepstrum_len;

    float         *analysis_buf;
    float         *dump_buf;
    float         *kernel_tmp_buf;
    float         *kernel_buf;
    float         *cepstrum_buf;
    float         *conv_buf;
    OverlapIndex  *conv_idx;
    int           fir_len;
    int           nsamples_max;
    int64_t       next_pts;
    int           frame_nsamples_max;
    int           remaining;

    char          *gain_cmd;
    char          *gain_entry_cmd;
    const char    *gain;
    const char    *gain_entry;
    double        delay;
    double        accuracy;
    int           wfunc;
    int           fixed;
    int           multi;
    int           zero_phase;
    int           scale;
    char          *dumpfile;
    int           dumpscale;
    int           fft2;
    int           min_phase;

    int           nb_gain_entry;
    int           gain_entry_err;
    GainEntry     gain_entry_tbl[NB_GAIN_ENTRY_MAX];
} FIREqualizerContext;
#define OFFSET(x) offsetof(FIREqualizerContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SELECT_GAIN(s) (s->gain_cmd ? s->gain_cmd : s->gain)
#define SELECT_GAIN_ENTRY(s) (s->gain_entry_cmd ? s->gain_entry_cmd : s->gain_entry)

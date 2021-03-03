#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct SincContext {
    const AVClass *class;

    int sample_rate, nb_samples;
    float att, beta, phase, Fc0, Fc1, tbw0, tbw1;
    int num_taps[2];
    int round;

    int n, rdft_len;
    float *coeffs;
    int64_t pts;

    RDFTContext *rdft, *irdft;
} SincContext;
#define PACK(h, n)   h[1] = h[n]
#define UNPACK(h, n) h[n] = h[1], h[n + 1] = h[1] = 0;
#define SQR(a) ((a) * (a))
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OFFSET(x) offsetof(SincContext, x)

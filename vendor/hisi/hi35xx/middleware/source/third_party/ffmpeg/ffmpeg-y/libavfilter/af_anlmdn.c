#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "af_anlmdndsp.h"
#define WEIGHT_LUT_NBITS 20
#define WEIGHT_LUT_SIZE  (1<<WEIGHT_LUT_NBITS)
#define SQR(x) ((x) * (x))
typedef struct AudioNLMeansContext {
    const AVClass *class;

    float a;
    int64_t pd;
    int64_t rd;
    float m;
    int om;

    float pdiff_lut_scale;
    float weight_lut[WEIGHT_LUT_SIZE];

    int K;
    int S;
    int N;
    int H;

    int offset;
    AVFrame *in;
    AVFrame *cache;

    int64_t pts;

    AVAudioFifo *fifo;
    int eof_left;

    AudioNLMDNDSPContext dsp;
} AudioNLMeansContext;
#define OFFSET(x) offsetof(AudioNLMeansContext, x)
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/xga_font_data.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
typedef struct Pair {
    int a, b;
} Pair;
typedef struct BiquadContext {
    double a0, a1, a2;
    double b0, b1, b2;
    double i1, i2;
    double o1, o2;
} BiquadContext;
typedef struct IIRChannel {
    int nb_ab[2];
    double *ab[2];
    double g;
    double *cache[2];
    BiquadContext *biquads;
    int clippings;
} IIRChannel;
typedef struct AudioIIRContext {
    const AVClass *class;
    char *a_str, *b_str, *g_str;
    double dry_gain, wet_gain;
    double mix;
    int format;
    int process;
    int precision;
    int response;
    int w, h;
    int ir_channel;
    AVRational rate;

    AVFrame *video;

    IIRChannel *iir;
    int channels;
    enum AVSampleFormat sample_format;

    int (*iir_channel)(AVFilterContext *ctx, void *arg, int ch, int nb_jobs);
} AudioIIRContext;
#define IIR_CH(name, type, min, max, need_clipping)                     \
#define SERIAL_IIR_CH(name, type, min, max, need_clipping)                  \
#define OFFSET(x) offsetof(AudioIIRContext, x)
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define VF AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

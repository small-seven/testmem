#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "generate_wave_table.h"
typedef struct ChorusContext {
    const AVClass *class;
    float in_gain, out_gain;
    char *delays_str;
    char *decays_str;
    char *speeds_str;
    char *depths_str;
    float *delays;
    float *decays;
    float *speeds;
    float *depths;
    uint8_t **chorusbuf;
    int **phase;
    int *length;
    int32_t **lookup_table;
    int *counter;
    int num_chorus;
    int max_samples;
    int channels;
    int modulation;
    int fade_out;
    int64_t next_pts;
} ChorusContext;
#define OFFSET(x) offsetof(ChorusContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define MOD(a, b) (((a) >= (b)) ? (a) - (b) : (a))

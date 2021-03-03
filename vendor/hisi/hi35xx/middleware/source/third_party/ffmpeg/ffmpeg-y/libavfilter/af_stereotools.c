#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
typedef struct StereoToolsContext {
    const AVClass *class;

    int softclip;
    int mute_l;
    int mute_r;
    int phase_l;
    int phase_r;
    int mode;
    int bmode_in;
    int bmode_out;
    double slev;
    double sbal;
    double mlev;
    double mpan;
    double phase;
    double base;
    double delay;
    double balance_in;
    double balance_out;
    double phase_sin_coef;
    double phase_cos_coef;
    double sc_level;
    double inv_atan_shape;
    double level_in;
    double level_out;

    double *buffer;
    int length;
    int pos;
} StereoToolsContext;
#define OFFSET(x) offsetof(StereoToolsContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

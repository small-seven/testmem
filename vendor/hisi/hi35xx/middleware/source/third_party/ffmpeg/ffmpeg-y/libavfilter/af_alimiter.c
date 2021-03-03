#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct AudioLimiterContext {
    const AVClass *class;

    double limit;
    double attack;
    double release;
    double att;
    double level_in;
    double level_out;
    int auto_release;
    int auto_level;
    double asc;
    int asc_c;
    int asc_pos;
    double asc_coeff;

    double *buffer;
    int buffer_size;
    int pos;
    int *nextpos;
    double *nextdelta;

    double delta;
    int nextiter;
    int nextlen;
    int asc_changed;
} AudioLimiterContext;
#define OFFSET(x) offsetof(AudioLimiterContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM

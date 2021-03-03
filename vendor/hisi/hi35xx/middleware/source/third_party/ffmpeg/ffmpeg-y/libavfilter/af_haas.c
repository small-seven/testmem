#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#define MAX_HAAS_DELAY 40
typedef struct HaasContext {
    const AVClass *class;

    int par_m_source;
    double par_delay0;
    double par_delay1;
    int par_phase0;
    int par_phase1;
    int par_middle_phase;
    double par_side_gain;
    double par_gain0;
    double par_gain1;
    double par_balance0;
    double par_balance1;
    double level_in;
    double level_out;

    double *buffer;
    size_t buffer_size;
    uint32_t write_ptr;
    uint32_t delay[2];
    double balance_l[2];
    double balance_r[2];
    double phase0;
    double phase1;
} HaasContext;
#define OFFSET(x) offsetof(HaasContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct CompensationDelayContext {
    const AVClass *class;
    int distance_mm;
    int distance_cm;
    int distance_m;
    double dry, wet;
    int temp;

    unsigned delay;
    unsigned w_ptr;
    unsigned buf_size;
    AVFrame *delay_frame;
} CompensationDelayContext;
#define OFFSET(x) offsetof(CompensationDelayContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define COMP_DELAY_MAX_DISTANCE            (100.0 * 100.0 + 100.0 * 1.0 + 1.0)
#define COMP_DELAY_SOUND_SPEED_KM_H(temp)  1.85325 * (643.95 * sqrt(((temp + 273.15) / 273.15)))
#define COMP_DELAY_SOUND_SPEED_CM_S(temp)  (COMP_DELAY_SOUND_SPEED_KM_H(temp) * (1000.0 * 100.0) /* cm/km */ / (60.0 * 60.0) /* s/h */)
#define COMP_DELAY_SOUND_FRONT_DELAY(temp) (1.0 / COMP_DELAY_SOUND_SPEED_CM_S(temp))
#define COMP_DELAY_MAX_DELAY               (COMP_DELAY_MAX_DISTANCE * COMP_DELAY_SOUND_FRONT_DELAY(50))

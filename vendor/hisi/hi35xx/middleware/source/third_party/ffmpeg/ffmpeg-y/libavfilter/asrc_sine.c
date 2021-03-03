#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct SineContext {
    const AVClass *class;
    double frequency;
    double beep_factor;
    char *samples_per_frame;
    AVExpr *samples_per_frame_expr;
    int sample_rate;
    int64_t duration;
    int16_t *sin;
    int64_t pts;
    uint32_t phi;  ///< current phase of the sine (2pi = 1<<32)
    uint32_t dphi; ///< phase increment between two samples
    unsigned beep_period;
    unsigned beep_index;
    unsigned beep_length;
    uint32_t phi_beep;  ///< current phase of the beep
    uint32_t dphi_beep; ///< phase increment of the beep
} SineContext;
#define CONTEXT SineContext
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OPT_GENERIC(name, field, def, min, max, descr, type, deffield, ...) \
#define OPT_INT(name, field, def, min, max, descr, ...) \
#define OPT_DBL(name, field, def, min, max, descr, ...) \
#define OPT_DUR(name, field, def, min, max, descr, ...) \
#define OPT_STR(name, field, def, min, max, descr, ...) \
#define LOG_PERIOD 15
#define AMPLITUDE 4095
#define AMPLITUDE_SHIFT 3

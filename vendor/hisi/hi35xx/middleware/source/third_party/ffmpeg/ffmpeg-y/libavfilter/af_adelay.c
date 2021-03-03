#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "internal.h"
typedef struct ChanDelay {
    int delay;
    unsigned delay_index;
    unsigned index;
    uint8_t *samples;
} ChanDelay;
typedef struct AudioDelayContext {
    const AVClass *class;
    char *delays;
    ChanDelay *chandelay;
    int nb_delays;
    int block_align;
    int64_t padding;
    int64_t max_delay;
    int64_t next_pts;
    int eof;

    void (*delay_channel)(ChanDelay *d, int nb_samples,
                          const uint8_t *src, uint8_t *dst);
} AudioDelayContext;
#define OFFSET(x) offsetof(AudioDelayContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define DELAY(name, type, fill)                                           \

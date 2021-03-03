#include <pocketsphinx/pocketsphinx.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ASRContext {
    const AVClass *class;

    int   rate;
    char *hmm;
    char *dict;
    char *lm;
    char *lmctl;
    char *lmname;
    char *logfn;

    ps_decoder_t *ps;
    cmd_ln_t *config;

    int utt_started;
} ASRContext;
#define OFFSET(x) offsetof(ASRContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM

#include <twolame.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "mpegaudio.h"
typedef struct TWOLAMEContext {
    AVClass *class;
    int mode;
    int psymodel;
    int energy;
    int error_protection;
    int copyright;
    int original;
    int verbosity;

    twolame_options *glopts;
    int64_t next_pts;
} TWOLAMEContext;
#define OFFSET(x) offsetof(TWOLAMEContext, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM

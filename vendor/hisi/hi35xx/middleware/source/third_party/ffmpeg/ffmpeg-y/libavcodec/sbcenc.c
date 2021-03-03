#include <stdbool.h>
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "profiles.h"
#include "put_bits.h"
#include "sbc.h"
#include "sbcdsp.h"
typedef struct SBCEncContext {
    AVClass *class;
    int64_t max_delay;
    int msbc;
    DECLARE_ALIGNED(SBC_ALIGN, struct sbc_frame, frame);
    DECLARE_ALIGNED(SBC_ALIGN, SBCDSPContext, dsp);
} SBCEncContext;
#define OFFSET(x) offsetof(SBCEncContext, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM

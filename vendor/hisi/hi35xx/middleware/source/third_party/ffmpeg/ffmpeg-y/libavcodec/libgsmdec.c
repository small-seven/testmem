#include "config.h"
#if HAVE_GSM_H
#include <gsm.h>
#else
#include <gsm/gsm.h>
#endif
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "avcodec.h"
#include "internal.h"
#include "gsm.h"
typedef struct LibGSMDecodeContext {
    struct gsm_state *state;
} LibGSMDecodeContext;
#if CONFIG_LIBGSM_DECODER
#endif
#if CONFIG_LIBGSM_MS_DECODER
#endif

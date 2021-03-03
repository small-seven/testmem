#include "config.h"
#if HAVE_GSM_H
#include <gsm.h>
#else
#include <gsm/gsm.h>
#endif
#include "libavutil/common.h"
#include "avcodec.h"
#include "internal.h"
#include "gsm.h"
#if CONFIG_LIBGSM_ENCODER
#endif
#if CONFIG_LIBGSM_MS_ENCODER
#endif

#include <va/va.h>
#include <va/va_enc_vp9.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "avcodec.h"
#include "internal.h"
#include "vaapi_encode.h"
#define VP9_MAX_QUANT 255
typedef struct VAAPIEncodeVP9Picture {
    int slot;
} VAAPIEncodeVP9Picture;
typedef struct VAAPIEncodeVP9Context {
    VAAPIEncodeContext common;

    // User options.
    int loop_filter_level;
    int loop_filter_sharpness;

    // Derived settings.
    int q_idx_idr;
    int q_idx_p;
    int q_idx_b;
} VAAPIEncodeVP9Context;
#define OFFSET(x) offsetof(VAAPIEncodeVP9Context, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)

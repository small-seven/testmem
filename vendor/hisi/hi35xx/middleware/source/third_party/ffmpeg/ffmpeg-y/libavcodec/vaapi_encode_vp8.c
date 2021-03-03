#include <va/va.h>
#include <va/va_enc_vp8.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "avcodec.h"
#include "internal.h"
#include "vaapi_encode.h"
#include "vp8.h"
typedef struct VAAPIEncodeVP8Context {
    VAAPIEncodeContext common;

    // User options.
    int loop_filter_level;
    int loop_filter_sharpness;

    // Derived settings.
    int q_index_i;
    int q_index_p;
} VAAPIEncodeVP8Context;
#define vseq_var(name)     vseq->name, name
#define vseq_field(name)   vseq->seq_fields.bits.name, name
#define vpic_var(name)     vpic->name, name
#define vpic_field(name)   vpic->pic_fields.bits.name, name
#define OFFSET(x) offsetof(VAAPIEncodeVP8Context, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)

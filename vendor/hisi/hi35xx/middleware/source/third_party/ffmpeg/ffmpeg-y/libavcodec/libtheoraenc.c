#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/pixdesc.h"
#include "libavutil/log.h"
#include "libavutil/base64.h"
#include "avcodec.h"
#include "internal.h"
#include <theora/theoraenc.h>
typedef struct TheoraContext {
    th_enc_ctx *t_state;
    uint8_t    *stats;
    int         stats_size;
    int         stats_offset;
    int         uv_hshift;
    int         uv_vshift;
    int         keyframe_mask;
} TheoraContext;
#ifdef TH_ENCCTL_2PASS_OUT
#else
#endif
#ifdef TH_ENCCTL_2PASS_IN
#else
#endif
#if FF_API_CODED_FRAME
#endif

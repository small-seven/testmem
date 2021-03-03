#include "libwebpenc_common.h"
typedef LibWebPContextCommon LibWebPContext;

static av_cold int libwebp_encode_init(AVCodecContext *avctx)
{
    return ff_libwebp_encode_init_common(avctx);
}
#if (WEBP_ENCODER_ABI_VERSION > 0x0203)
#else
#endif

#define VPX_CODEC_DISABLE_COMPAT 1
#include <vpx/vpx_decoder.h>
#include <vpx/vp8dx.h>
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "libvpx.h"
#include "profiles.h"
typedef struct VPxDecoderContext {
    struct vpx_codec_ctx decoder;
    struct vpx_codec_ctx decoder_alpha;
    int has_alpha_channel;
} VPxContext;
#if VPX_IMAGE_ABI_VERSION >= 4
#endif
#if CONFIG_LIBVPX_VP9_DECODER
#endif
#if CONFIG_LIBVPX_VP8_DECODER && CONFIG_LIBVPX_VP9_DECODER
#elif CONFIG_LIBVPX_VP8_DECODER
#else
#endif
static av_cold int vpx_free(AVCodecContext *avctx)
{
    VPxContext *ctx = avctx->priv_data;
    vpx_codec_destroy(&ctx->decoder);
    if (ctx->has_alpha_channel)
        vpx_codec_destroy(&ctx->decoder_alpha);
    return 0;
}
#if CONFIG_LIBVPX_VP8_DECODER
#endif /* CONFIG_LIBVPX_VP8_DECODER */
#if CONFIG_LIBVPX_VP9_DECODER
#endif /* CONFIG_LIBVPX_VP9_DECODER */

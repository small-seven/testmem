#include <aom/aom_decoder.h>
#include <aom/aomdx.h>
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "internal.h"
#include "profiles.h"
typedef struct AV1DecodeContext {
    struct aom_codec_ctx decoder;
} AV1DecodeContext;
static av_cold int aom_free(AVCodecContext *avctx)
{
    AV1DecodeContext *ctx = avctx->priv_data;
    aom_codec_destroy(&ctx->decoder);
    return 0;
}

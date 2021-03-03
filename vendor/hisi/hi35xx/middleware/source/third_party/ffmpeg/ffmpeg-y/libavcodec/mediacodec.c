#include "config.h"
#include "libavutil/error.h"
#include "mediacodec.h"
#if CONFIG_MEDIACODEC
#include <jni.h>
#include "libavcodec/avcodec.h"
#include "libavutil/mem.h"
#include "ffjni.h"
#include "mediacodecdec_common.h"
#include "version.h"
void av_mediacodec_default_free(AVCodecContext *avctx)
{
    JNIEnv *env = NULL;

    AVMediaCodecContext *ctx = avctx->hwaccel_context;

    if (!ctx) {
        return;
    }

    env = ff_jni_get_env(avctx);
    if (!env) {
        return;
    }

    if (ctx->surface) {
        (*env)->DeleteGlobalRef(env, ctx->surface);
        ctx->surface = NULL;
    }

    av_freep(&avctx->hwaccel_context);
}
#else
#include <stdlib.h>
void av_mediacodec_default_free(AVCodecContext *avctx)
{
}
#endif

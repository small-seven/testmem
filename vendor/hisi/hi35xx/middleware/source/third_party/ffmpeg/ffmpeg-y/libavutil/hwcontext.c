#include "config.h"
#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "imgutils.h"
#include "log.h"
#include "mem.h"
#include "pixdesc.h"
#include "pixfmt.h"
#if CONFIG_CUDA
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_LIBDRM
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_OPENCL
#endif
#if CONFIG_QSV
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_VDPAU
#endif
#if CONFIG_VIDEOTOOLBOX
#endif
#if CONFIG_MEDIACODEC
#endif
static void hwdevice_ctx_free(void *opaque, uint8_t *data)
{
    AVHWDeviceContext *ctx = (AVHWDeviceContext*)data;

    /* uninit might still want access the hw context and the user
     * free() callback might destroy it, so uninit has to be called first */
    if (ctx->internal->hw_type->device_uninit)
        ctx->internal->hw_type->device_uninit(ctx);

    if (ctx->free)
        ctx->free(ctx);

    av_buffer_unref(&ctx->internal->source_device);

    av_freep(&ctx->hwctx);
    av_freep(&ctx->internal->priv);
    av_freep(&ctx->internal);
    av_freep(&ctx);
}
static void hwframe_ctx_free(void *opaque, uint8_t *data)
{
    AVHWFramesContext *ctx = (AVHWFramesContext*)data;

    if (ctx->internal->pool_internal)
        av_buffer_pool_uninit(&ctx->internal->pool_internal);

    if (ctx->internal->hw_type->frames_uninit)
        ctx->internal->hw_type->frames_uninit(ctx);

    if (ctx->free)
        ctx->free(ctx);

    av_buffer_unref(&ctx->internal->source_frames);

    av_buffer_unref(&ctx->device_ref);

    av_freep(&ctx->hwctx);
    av_freep(&ctx->internal->priv);
    av_freep(&ctx->internal);
    av_freep(&ctx);
}
static int hwframe_pool_prealloc(AVBufferRef *ref)
{
    AVHWFramesContext *ctx = (AVHWFramesContext*)ref->data;
    AVFrame **frames;
    int i, ret = 0;

    frames = av_mallocz_array(ctx->initial_pool_size, sizeof(*frames));
    if (!frames)
        return AVERROR(ENOMEM);

    for (i = 0; i < ctx->initial_pool_size; i++) {
        frames[i] = av_frame_alloc();
        if (!frames[i])
            goto fail;

        ret = av_hwframe_get_buffer(ref, frames[i], 0);
        if (ret < 0)
            goto fail;
    }

fail:
    for (i = 0; i < ctx->initial_pool_size; i++)
        av_frame_free(&frames[i]);
    av_freep(&frames);

    return ret;
}
void av_hwframe_constraints_free(AVHWFramesConstraints **constraints)
{
    if (*constraints) {
        av_freep(&(*constraints)->valid_hw_formats);
        av_freep(&(*constraints)->valid_sw_formats);
    }
    av_freep(constraints);
}

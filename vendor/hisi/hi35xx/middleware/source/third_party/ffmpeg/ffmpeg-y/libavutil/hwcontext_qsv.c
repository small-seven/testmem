#include <stdint.h>
#include <string.h>
#include <mfx/mfxvideo.h>
#include "config.h"
#if HAVE_PTHREADS
#include <pthread.h>
#endif
#if CONFIG_VAAPI
#include "hwcontext_vaapi.h"
#endif
#if CONFIG_DXVA2
#include "hwcontext_dxva2.h"
#endif
#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "hwcontext_qsv.h"
#include "mem.h"
#include "pixfmt.h"
#include "pixdesc.h"
#include "time.h"
typedef struct QSVDevicePriv {
    AVBufferRef *child_device_ctx;
} QSVDevicePriv;
typedef struct QSVDeviceContext {
    mfxHDL              handle;
    mfxHandleType       handle_type;
    mfxVersion          ver;
    mfxIMPL             impl;

    enum AVHWDeviceType child_device_type;
    enum AVPixelFormat  child_pix_fmt;
} QSVDeviceContext;
typedef struct QSVFramesContext {
    mfxSession session_download;
    int session_download_init;
    mfxSession session_upload;
    int session_upload_init;
#if HAVE_PTHREADS
    pthread_mutex_t session_lock;
    pthread_cond_t session_cond;
#endif

    AVBufferRef *child_frames_ref;
    mfxFrameSurface1 *surfaces_internal;
    int             nb_surfaces_used;

    // used in the frame allocator for non-opaque surfaces
    mfxMemId *mem_ids;
    // used in the opaque alloc request for opaque surfaces
    mfxFrameSurface1 **surface_ptrs;

    mfxExtOpaqueSurfaceAlloc opaque_alloc;
    mfxExtBuffer *ext_buffers[1];
} QSVFramesContext;
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
#if HAVE_PTHREADS
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
static mfxStatus frame_free(mfxHDL pthis, mfxFrameAllocResponse *resp)
{
    return MFX_ERR_NONE;
}
#if HAVE_PTHREADS
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
#if HAVE_PTHREADS
#endif
#if HAVE_PTHREADS
#endif
#if HAVE_PTHREADS
#endif
#if HAVE_PTHREADS
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif
static void qsv_device_free(AVHWDeviceContext *ctx)
{
    AVQSVDeviceContext *hwctx = ctx->hwctx;
    QSVDevicePriv       *priv = ctx->user_opaque;

    if (hwctx->session)
        MFXClose(hwctx->session);

    av_buffer_unref(&priv->child_device_ctx);
    av_freep(&priv);
}
#if CONFIG_VAAPI
#endif
#if CONFIG_DXVA2
#endif

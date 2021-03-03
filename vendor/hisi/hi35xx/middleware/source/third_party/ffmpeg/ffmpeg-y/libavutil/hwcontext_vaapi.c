#include "config.h"
#if HAVE_VAAPI_X11
#   include <va/va_x11.h>
#endif
#if HAVE_VAAPI_DRM
#   include <va/va_drm.h>
#endif
#if CONFIG_LIBDRM
#   include <va/va_drmcommon.h>
#   include <xf86drm.h>
#   include <drm_fourcc.h>
#   ifndef DRM_FORMAT_MOD_INVALID
#       define DRM_FORMAT_MOD_INVALID ((1ULL << 56) - 1)
#   endif
#endif
#include <fcntl.h>
#if HAVE_UNISTD_H
#   include <unistd.h>
#endif
#include "avassert.h"
#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_drm.h"
#include "hwcontext_internal.h"
#include "hwcontext_vaapi.h"
#include "mem.h"
#include "pixdesc.h"
#include "pixfmt.h"
typedef struct VAAPIDevicePriv {
#if HAVE_VAAPI_X11
    Display *x11_display;
#endif

    int drm_fd;
} VAAPIDevicePriv;
typedef struct VAAPISurfaceFormat {
    enum AVPixelFormat pix_fmt;
    VAImageFormat image_format;
} VAAPISurfaceFormat;
typedef struct VAAPIDeviceContext {
    // Surface formats which can be used with this device.
    VAAPISurfaceFormat *formats;
    int              nb_formats;
} VAAPIDeviceContext;
typedef struct VAAPIFramesContext {
    // Surface attributes set at create time.
    VASurfaceAttrib *attributes;
    int           nb_attributes;
    // RT format of the underlying surface (Intel driver ignores this anyway).
    unsigned int rt_format;
    // Whether vaDeriveImage works.
    int derive_works;
} VAAPIFramesContext;
typedef struct VAAPIMapping {
    // Handle to the derived or copied image which is mapped.
    VAImage image;
    // The mapping flags actually used.
    int flags;
} VAAPIMapping;
typedef struct VAAPIFormat {
    unsigned int fourcc;
    unsigned int rt_format;
    enum AVPixelFormat pix_fmt;
    int chroma_planes_swapped;
} VAAPIFormatDescriptor;
#define MAP(va, rt, av, swap_uv) { \
#ifdef VA_FOURCC_I420
#endif
#ifdef VA_FOURCC_YV16
#endif
#ifdef VA_FOURCC_P010
#endif
#ifdef VA_FOURCC_ABGR
#endif
#undef MAP
#if !VA_CHECK_VERSION(1, 0, 0)
#endif
static void vaapi_buffer_free(void *opaque, uint8_t *data)
{
    AVHWFramesContext     *hwfc = opaque;
    AVVAAPIDeviceContext *hwctx = hwfc->device_ctx->hwctx;
    VASurfaceID surface_id;
    VAStatus vas;

    surface_id = (VASurfaceID)(uintptr_t)data;

    vas = vaDestroySurfaces(hwctx->display, &surface_id, 1);
    if (vas != VA_STATUS_SUCCESS) {
        av_log(hwfc, AV_LOG_ERROR, "Failed to destroy surface %#x: "
               "%d (%s).\n", surface_id, vas, vaErrorStr(vas));
    }
}
#if CONFIG_LIBDRM
#define DRM_MAP(va, layers, ...) { \
#ifdef DRM_FORMAT_R8
#endif
#if defined(VA_FOURCC_P010) && defined(DRM_FORMAT_R16)
#endif
#ifdef VA_FOURCC_ABGR
#endif
#undef DRM_MAP
#if VA_CHECK_VERSION(1, 1, 0)
#endif
#if VA_CHECK_VERSION(0, 36, 0)
typedef struct VAAPIDRMImageBufferMapping {
    VAImage      image;
    VABufferInfo buffer_info;

    AVDRMFrameDescriptor drm_desc;
} VAAPIDRMImageBufferMapping;
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#endif
#if VA_CHECK_VERSION(0, 36, 0)
#endif
#endif /* CONFIG_LIBDRM */
#if CONFIG_LIBDRM
#endif
#if CONFIG_LIBDRM
#endif
static void vaapi_device_free(AVHWDeviceContext *ctx)
{
    AVVAAPIDeviceContext *hwctx = ctx->hwctx;
    VAAPIDevicePriv      *priv  = ctx->user_opaque;

    if (hwctx->display)
        vaTerminate(hwctx->display);

#if HAVE_VAAPI_X11
    if (priv->x11_display)
        XCloseDisplay(priv->x11_display);
#endif

    if (priv->drm_fd >= 0)
        close(priv->drm_fd);

    av_freep(&priv);
}
#if CONFIG_VAAPI_1
#endif
#if CONFIG_VAAPI_1
#endif
#if HAVE_VAAPI_DRM
#if CONFIG_LIBDRM
#endif
#if CONFIG_LIBDRM
#endif
#endif
#if HAVE_VAAPI_X11
#endif
#if VA_CHECK_VERSION(0, 38, 0)
#else
#endif
#if HAVE_VAAPI_DRM
#endif

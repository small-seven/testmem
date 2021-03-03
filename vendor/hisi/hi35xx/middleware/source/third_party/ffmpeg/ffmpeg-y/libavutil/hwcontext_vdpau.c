#include "config.h"
#include <stdint.h>
#include <string.h>
#include <vdpau/vdpau.h>
#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "hwcontext_vdpau.h"
#include "mem.h"
#include "pixfmt.h"
#include "pixdesc.h"
typedef struct VDPAUDeviceContext {
    VdpVideoSurfaceQueryGetPutBitsYCbCrCapabilities *get_transfer_caps;
    VdpVideoSurfaceGetBitsYCbCr                     *get_data;
    VdpVideoSurfacePutBitsYCbCr                     *put_data;
    VdpVideoSurfaceCreate                           *surf_create;
    VdpVideoSurfaceDestroy                          *surf_destroy;

    enum AVPixelFormat *pix_fmts[3];
    int              nb_pix_fmts[3];
} VDPAUDeviceContext;
typedef struct VDPAUFramesContext {
    VdpVideoSurfaceGetBitsYCbCr *get_data;
    VdpVideoSurfacePutBitsYCbCr *put_data;
    VdpChromaType chroma_type;
    int chroma_idx;

    const enum AVPixelFormat *pix_fmts;
    int                       nb_pix_fmts;
} VDPAUFramesContext;
typedef struct VDPAUPixFmtMap {
    VdpYCbCrFormat vdpau_fmt;
    enum AVPixelFormat pix_fmt;
} VDPAUPixFmtMap;
#ifdef VDP_YCBCR_FORMAT_Y_U_V_444
#endif
#define GET_CALLBACK(id, result)                                                \
static void vdpau_buffer_free(void *opaque, uint8_t *data)
{
    AVHWFramesContext          *ctx = opaque;
    VDPAUDeviceContext *device_priv = ctx->device_ctx->internal->priv;
    VdpVideoSurface            surf = (VdpVideoSurface)(uintptr_t)data;

    device_priv->surf_destroy(surf);
}
#ifdef VDP_YCBCR_FORMAT_Y_U_V_444
#endif
#ifdef VDP_YCBCR_FORMAT_Y_U_V_444
#endif
#if HAVE_VDPAU_X11
#include <vdpau/vdpau_x11.h>
#include <X11/Xlib.h>
typedef struct VDPAUDevicePriv {
    VdpDeviceDestroy *device_destroy;
    Display *dpy;
} VDPAUDevicePriv;
static void vdpau_device_free(AVHWDeviceContext *ctx)
{
    AVVDPAUDeviceContext *hwctx = ctx->hwctx;
    VDPAUDevicePriv       *priv = ctx->user_opaque;

    if (priv->device_destroy)
        priv->device_destroy(hwctx->device);
    if (priv->dpy)
        XCloseDisplay(priv->dpy);
    av_freep(&priv);
}
#endif
#if HAVE_VDPAU_X11
#endif

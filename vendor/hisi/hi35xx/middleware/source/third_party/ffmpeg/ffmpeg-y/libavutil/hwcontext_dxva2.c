#include <windows.h>
#define DXVA2API_USE_BITFIELDS
#define COBJMACROS
#include <d3d9.h>
#include <dxva2api.h>
#include <initguid.h>
#include "avassert.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_dxva2.h"
#include "hwcontext_internal.h"
#include "imgutils.h"
#include "pixdesc.h"
#include "pixfmt.h"
#include "compat/w32dlfcn.h"
typedef IDirect3D9* WINAPI pDirect3DCreate9(UINT);
typedef HRESULT WINAPI pDirect3DCreate9Ex(UINT, IDirect3D9Ex **);
typedef HRESULT WINAPI pCreateDeviceManager9(UINT *, IDirect3DDeviceManager9 **);

#define FF_D3DCREATE_FLAGS (D3DCREATE_SOFTWARE_VERTEXPROCESSING | \
                            D3DCREATE_MULTITHREADED | \
                            D3DCREATE_FPU_PRESERVE)

static const D3DPRESENT_PARAMETERS dxva2_present_params = {
    .Windowed         = TRUE,
    .BackBufferWidth  = 640,
    .BackBufferHeight = 480,
    .BackBufferCount  = 0,
    .SwapEffect       = D3DSWAPEFFECT_DISCARD,
    .Flags            = D3DPRESENTFLAG_VIDEO,
};
typedef struct DXVA2Mapping {
    uint32_t palette_dummy[256];
} DXVA2Mapping;
typedef struct DXVA2FramesContext {
    IDirect3DSurface9 **surfaces_internal;
    int              nb_surfaces_used;

    HANDLE  device_handle;
    IDirectXVideoAccelerationService *service;

    D3DFORMAT format;
} DXVA2FramesContext;
typedef struct DXVA2DevicePriv {
    HMODULE d3dlib;
    HMODULE dxva2lib;

    HANDLE device_handle;

    IDirect3D9       *d3d9;
    IDirect3DDevice9 *d3d9device;
} DXVA2DevicePriv;
static void dxva2_device_free(AVHWDeviceContext *ctx)
{
    AVDXVA2DeviceContext *hwctx = ctx->hwctx;
    DXVA2DevicePriv       *priv = ctx->user_opaque;

    if (hwctx->devmgr && priv->device_handle != INVALID_HANDLE_VALUE)
        IDirect3DDeviceManager9_CloseDeviceHandle(hwctx->devmgr, priv->device_handle);

    if (hwctx->devmgr)
        IDirect3DDeviceManager9_Release(hwctx->devmgr);

    if (priv->d3d9device)
        IDirect3DDevice9_Release(priv->d3d9device);

    if (priv->d3d9)
        IDirect3D9_Release(priv->d3d9);

    if (priv->d3dlib)
        dlclose(priv->d3dlib);

    if (priv->dxva2lib)
        dlclose(priv->dxva2lib);

    av_freep(&ctx->user_opaque);
}

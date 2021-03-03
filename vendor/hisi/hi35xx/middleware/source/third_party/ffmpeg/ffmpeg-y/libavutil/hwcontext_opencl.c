#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <string.h>
#include "config.h"
#include "avassert.h"
#include "avstring.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "hwcontext_opencl.h"
#include "mem.h"
#include "pixdesc.h"
#if HAVE_OPENCL_VAAPI_BEIGNET
#include <unistd.h>
#include <va/va.h>
#include <va/va_drmcommon.h>
#include <CL/cl_intel.h>
#include "hwcontext_vaapi.h"
#endif
#if HAVE_OPENCL_DRM_BEIGNET
#include <unistd.h>
#include <CL/cl_intel.h>
#include "hwcontext_drm.h"
#endif
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#if CONFIG_LIBMFX
#include <mfx/mfxstructures.h>
#endif
#include <va/va.h>
#include <CL/cl_va_api_media_sharing_intel.h>
#include "hwcontext_vaapi.h"
#endif
#if HAVE_OPENCL_DXVA2
#define COBJMACROS
#include <CL/cl_dx9_media_sharing.h>
#include <dxva2api.h>
#include "hwcontext_dxva2.h"
#endif
#if HAVE_OPENCL_D3D11
#include <CL/cl_d3d11.h>
#include "hwcontext_d3d11va.h"
#endif
#if HAVE_OPENCL_DRM_ARM
#include <CL/cl_ext.h>
#include <drm_fourcc.h>
#include "hwcontext_drm.h"
#endif
typedef struct OpenCLDeviceContext {
    // Default command queue to use for transfer/mapping operations on
    // the device.  If the user supplies one, this is a reference to it.
    // Otherwise, it is newly-created.
    cl_command_queue command_queue;

    // The platform the context exists on.  This is needed to query and
    // retrieve extension functions.
    cl_platform_id platform_id;

    // Platform/device-specific functions.
#if HAVE_OPENCL_DRM_BEIGNET
    int beignet_drm_mapping_usable;
    clCreateImageFromFdINTEL_fn clCreateImageFromFdINTEL;
#endif

#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
    int qsv_mapping_usable;
    clCreateFromVA_APIMediaSurfaceINTEL_fn
        clCreateFromVA_APIMediaSurfaceINTEL;
    clEnqueueAcquireVA_APIMediaSurfacesINTEL_fn
        clEnqueueAcquireVA_APIMediaSurfacesINTEL;
    clEnqueueReleaseVA_APIMediaSurfacesINTEL_fn
        clEnqueueReleaseVA_APIMediaSurfacesINTEL;
#endif

#if HAVE_OPENCL_DXVA2
    int dxva2_mapping_usable;
    cl_dx9_media_adapter_type_khr dx9_media_adapter_type;

    clCreateFromDX9MediaSurfaceKHR_fn
        clCreateFromDX9MediaSurfaceKHR;
    clEnqueueAcquireDX9MediaSurfacesKHR_fn
        clEnqueueAcquireDX9MediaSurfacesKHR;
    clEnqueueReleaseDX9MediaSurfacesKHR_fn
        clEnqueueReleaseDX9MediaSurfacesKHR;
#endif

#if HAVE_OPENCL_D3D11
    int d3d11_mapping_usable;
    clCreateFromD3D11Texture2DKHR_fn
        clCreateFromD3D11Texture2DKHR;
    clEnqueueAcquireD3D11ObjectsKHR_fn
        clEnqueueAcquireD3D11ObjectsKHR;
    clEnqueueReleaseD3D11ObjectsKHR_fn
        clEnqueueReleaseD3D11ObjectsKHR;
#endif

#if HAVE_OPENCL_DRM_ARM
    int drm_arm_mapping_usable;
#endif
} OpenCLDeviceContext;
typedef struct OpenCLFramesContext {
    // Command queue used for transfer/mapping operations on this frames
    // context.  If the user supplies one, this is a reference to it.
    // Otherwise, it is a reference to the default command queue for the
    // device.
    cl_command_queue command_queue;

#if HAVE_OPENCL_DXVA2 || HAVE_OPENCL_D3D11
    // For mapping APIs which have separate creation and acquire/release
    // steps, this stores the OpenCL memory objects corresponding to each
    // frame.
    int                   nb_mapped_frames;
    AVOpenCLFrameDescriptor *mapped_frames;
#endif
} OpenCLFramesContext;
static void opencl_device_free(AVHWDeviceContext *hwdev)
{
    AVOpenCLDeviceContext *hwctx = hwdev->hwctx;
    cl_int cle;

    cle = clReleaseContext(hwctx->context);
    if (cle != CL_SUCCESS) {
        av_log(hwdev, AV_LOG_ERROR, "Failed to release OpenCL "
               "context: %d.\n", cle);
    }
}
typedef struct OpenCLDeviceSelector {
    int platform_index;
    int device_index;
    void *context;
    int (*enumerate_platforms)(AVHWDeviceContext *hwdev,
                               cl_uint *nb_platforms,
                               cl_platform_id **platforms,
                               void *context);
    int (*filter_platform)    (AVHWDeviceContext *hwdev,
                               cl_platform_id platform_id,
                               const char *platform_name,
                               void *context);
    int (*enumerate_devices)  (AVHWDeviceContext *hwdev,
                               cl_platform_id platform_id,
                               const char *platform_name,
                               cl_uint *nb_devices,
                               cl_device_id **devices,
                               void *context);
    int (*filter_device)      (AVHWDeviceContext *hwdev,
                               cl_device_id device_id,
                               const char *device_name,
                               void *context);
} OpenCLDeviceSelector;
#define CL_FUNC(name, desc) do {                                \
#if HAVE_OPENCL_DRM_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
#endif
#undef CL_FUNC
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DXVA2 || HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
#endif
#if HAVE_OPENCL_DRM_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
#endif
#define CHANNEL_ORDER(order, type) \
#ifdef CL_ABGR
#endif
#undef CHANNEL_ORDER
static void opencl_pool_free(void *opaque, uint8_t *data)
{
    AVHWFramesContext       *hwfc = opaque;
    AVOpenCLFrameDescriptor *desc = (AVOpenCLFrameDescriptor*)data;
    cl_int cle;
    int p;

    for (p = 0; p < desc->nb_planes; p++) {
        cle = clReleaseMemObject(desc->planes[p]);
        if (cle != CL_SUCCESS) {
            av_log(hwfc, AV_LOG_ERROR, "Failed to release plane %d: "
                   "%d.\n", p, cle);
        }
    }

    av_free(desc);
}
#if HAVE_OPENCL_DXVA2 || HAVE_OPENCL_D3D11
#endif
typedef struct OpenCLMapping {
    // The mapped addresses for each plane.
    // The destination frame is not available when we unmap, so these
    // need to be stored separately.
    void *address[AV_NUM_DATA_POINTERS];
} OpenCLMapping;
#if HAVE_OPENCL_DRM_BEIGNET
typedef struct DRMBeignetToOpenCLMapping {
    AVFrame              *drm_frame;
    AVDRMFrameDescriptor *drm_desc;

    AVOpenCLFrameDescriptor frame;
} DRMBeignetToOpenCLMapping;
#if HAVE_OPENCL_VAAPI_BEIGNET
#endif /* HAVE_OPENCL_VAAPI_BEIGNET */
#endif /* HAVE_OPENCL_DRM_BEIGNET */
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#if CONFIG_LIBMFX
#endif
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
typedef struct DRMARMtoOpenCLMapping {
    int nb_objects;
    cl_mem object_buffers[AV_DRM_MAX_PLANES];
    int nb_planes;
    cl_mem plane_images[AV_DRM_MAX_PLANES];
} DRMARMtoOpenCLMapping;
#endif
#if HAVE_OPENCL_DRM_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
#endif
#if HAVE_OPENCL_DRM_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_BEIGNET
#endif
#if HAVE_OPENCL_VAAPI_INTEL_MEDIA
#endif
#if HAVE_OPENCL_DXVA2
#endif
#if HAVE_OPENCL_D3D11
#endif
#if HAVE_OPENCL_DRM_ARM
#endif

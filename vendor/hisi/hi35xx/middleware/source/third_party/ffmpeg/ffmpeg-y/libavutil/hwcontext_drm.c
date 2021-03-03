#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <drm.h>
#include <xf86drm.h>
#include "avassert.h"
#include "hwcontext.h"
#include "hwcontext_drm.h"
#include "hwcontext_internal.h"
#include "imgutils.h"
static void drm_device_free(AVHWDeviceContext *hwdev)
{
    AVDRMDeviceContext *hwctx = hwdev->hwctx;

    close(hwctx->fd);
}
typedef struct DRMMapping {
    // Address and length of each mmap()ed region.
    int nb_regions;
    void *address[AV_DRM_MAX_PLANES];
    size_t length[AV_DRM_MAX_PLANES];
} DRMMapping;

#include <fcntl.h>
#include <unistd.h>
#include <drm.h>
#include <drm_fourcc.h>
#include <drm_mode.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_drm.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
typedef struct KMSGrabContext {
    const AVClass *class;

    AVBufferRef *device_ref;
    AVHWDeviceContext *device;
    AVDRMDeviceContext *hwctx;

    AVBufferRef *frames_ref;
    AVHWFramesContext *frames;

    uint32_t plane_id;
    uint32_t drm_format;
    unsigned int width;
    unsigned int height;

    int64_t frame_delay;
    int64_t frame_last;

    const char *device_path;
    enum AVPixelFormat format;
    int64_t drm_format_modifier;
    int64_t source_plane;
    int64_t source_crtc;
    AVRational framerate;
} KMSGrabContext;
#ifdef DRM_FORMAT_R8
#endif
#ifdef DRM_FORMAT_R16
#endif
#define OFFSET(x) offsetof(KMSGrabContext, x)
#define FLAGS AV_OPT_FLAG_DECODING_PARAM

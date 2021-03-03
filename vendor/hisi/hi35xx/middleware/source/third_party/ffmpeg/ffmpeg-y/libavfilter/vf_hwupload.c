#include "libavutil/buffer.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_internal.h"
#include "libavutil/log.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct HWUploadContext {
    const AVClass *class;

    AVBufferRef       *hwdevice_ref;
    AVHWDeviceContext *hwdevice;

    AVBufferRef       *hwframes_ref;
    AVHWFramesContext *hwframes;
} HWUploadContext;

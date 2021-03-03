#include "libavutil/buffer.h"
#include "libavutil/hwcontext.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct CudaUploadContext {
    const AVClass *class;
    int device_idx;

    AVBufferRef *hwdevice;
    AVBufferRef *hwframe;
} CudaUploadContext;
#define OFFSET(x) offsetof(CudaUploadContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)

#include "libavutil/buffer.h"
#include "libavutil/hwcontext.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct HWDownloadContext {
    const AVClass *class;

    AVBufferRef       *hwframes_ref;
    AVHWFramesContext *hwframes;
} HWDownloadContext;

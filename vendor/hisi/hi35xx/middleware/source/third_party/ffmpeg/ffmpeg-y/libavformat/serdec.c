#include "libavutil/imgutils.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "avformat.h"
#define SER_MAGIC "LUCAM-RECORDER"
typedef struct SERDemuxerContext {
    const AVClass *class;
    int width, height;
    AVRational framerate;
    int64_t end;
} SERDemuxerContext;
#define OFFSET(x) offsetof(SERDemuxerContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM

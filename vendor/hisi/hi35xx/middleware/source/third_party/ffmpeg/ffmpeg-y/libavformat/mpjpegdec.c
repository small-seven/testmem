#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
typedef struct MPJPEGDemuxContext {
    const AVClass *class;
    char       *boundary;
    char       *searchstr;
    int         searchstr_len;
    int         strict_mime_boundary;
} MPJPEGDemuxContext;
#define OFFSET(x) offsetof(MPJPEGDemuxContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM

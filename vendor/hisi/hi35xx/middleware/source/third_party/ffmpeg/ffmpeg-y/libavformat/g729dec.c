#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
typedef struct G729DemuxerContext {
    AVClass *class;

    int bit_rate;
} G729DemuxerContext;
#define OFFSET(x) offsetof(G729DemuxerContext, x)

#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
typedef struct AFCDemuxContext {
    int64_t    data_end;
} AFCDemuxContext;

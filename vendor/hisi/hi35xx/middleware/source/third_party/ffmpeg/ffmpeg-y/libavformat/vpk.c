#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct VPKDemuxContext {
    unsigned block_count;
    unsigned current_block;
    unsigned last_block_size;
} VPKDemuxContext;

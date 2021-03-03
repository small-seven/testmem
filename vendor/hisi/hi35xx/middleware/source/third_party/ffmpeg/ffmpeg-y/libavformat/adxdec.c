#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define BLOCK_SIZE    18
#define BLOCK_SAMPLES 32
typedef struct ADXDemuxerContext {
    int header_size;
} ADXDemuxerContext;

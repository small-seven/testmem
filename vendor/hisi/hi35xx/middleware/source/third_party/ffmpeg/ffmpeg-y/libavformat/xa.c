#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define XA00_TAG MKTAG('X', 'A', 0, 0)
#define XAI0_TAG MKTAG('X', 'A', 'I', 0)
#define XAJ0_TAG MKTAG('X', 'A', 'J', 0)
typedef struct MaxisXADemuxContext {
    uint32_t out_size;
    uint32_t sent_bytes;
} MaxisXADemuxContext;

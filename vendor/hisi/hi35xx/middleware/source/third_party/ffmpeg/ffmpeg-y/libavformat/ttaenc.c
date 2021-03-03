#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "apetag.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
typedef struct TTAMuxContext {
    AVIOContext *seek_table;
    AVPacketList *queue, *queue_end;
    uint32_t nb_samples;
    int frame_size;
    int last_frame;
} TTAMuxContext;

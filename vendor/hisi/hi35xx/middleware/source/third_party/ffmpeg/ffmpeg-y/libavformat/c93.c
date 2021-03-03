#include "avformat.h"
#include "internal.h"
#include "voc.h"
#include "libavutil/intreadwrite.h"
typedef struct C93BlockRecord {
    uint16_t index;
    uint8_t length;
    uint8_t frames;
} C93BlockRecord;
typedef struct C93DemuxContext {
    VocDecContext voc;

    C93BlockRecord block_records[512];
    int current_block;

    uint32_t frame_offsets[32];
    int current_frame;
    int next_pkt_is_audio;

    AVStream *audio;
} C93DemuxContext;
#define C93_HAS_PALETTE 0x01
#define C93_FIRST_FRAME 0x02

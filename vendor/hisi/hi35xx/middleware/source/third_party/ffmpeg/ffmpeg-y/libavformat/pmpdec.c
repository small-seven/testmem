#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct {
    int cur_stream;
    int num_streams;
    int audio_packets;
    int current_packet;
    uint32_t *packet_sizes;
    int packet_sizes_alloc;
} PMPContext;

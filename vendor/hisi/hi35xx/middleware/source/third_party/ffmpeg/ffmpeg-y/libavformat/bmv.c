#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
typedef struct BMVContext {
    uint8_t *packet;
    int      size;
    int      get_next;
    int64_t  audio_pos;
} BMVContext;

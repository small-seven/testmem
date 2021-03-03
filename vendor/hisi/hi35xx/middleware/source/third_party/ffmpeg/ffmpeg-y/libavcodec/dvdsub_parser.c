#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
typedef struct DVDSubParseContext {
    uint8_t *packet;
    int packet_len;
    int packet_index;
} DVDSubParseContext;

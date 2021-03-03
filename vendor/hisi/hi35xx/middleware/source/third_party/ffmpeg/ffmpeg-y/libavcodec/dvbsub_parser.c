#include <inttypes.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "internal.h"
#define PARSE_BUF_SIZE  (65536)
typedef struct DVBSubParseContext {
    uint8_t *packet_buf;
    int packet_start;
    int packet_index;
    int in_packet;
} DVBSubParseContext;

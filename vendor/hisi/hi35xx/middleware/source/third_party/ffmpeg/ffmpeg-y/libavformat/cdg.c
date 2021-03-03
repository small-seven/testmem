#include "avformat.h"
#include "internal.h"
#define CDG_PACKET_SIZE    24
#define CDG_COMMAND        0x09
#define CDG_MASK           0x3F
typedef struct CDGContext {
    int got_first_packet;
} CDGContext;

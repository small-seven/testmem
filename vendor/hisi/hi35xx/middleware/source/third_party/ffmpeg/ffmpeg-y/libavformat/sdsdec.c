#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
typedef struct SDSContext {
    uint8_t data[120];
    int bit_depth;
    int size;
    void (*read_block)(const uint8_t *src, uint32_t *dst);
} SDSContext;
#define SDS_3BYTE_TO_INT_DECODE(x) (((x) & 0x7F) | (((x) & 0x7F00) >> 1) | (((x) & 0x7F0000) >> 2))

#include "avformat.h"
#include "caf.h"
#include "isom.h"
#include "avio_internal.h"
#include "libavutil/intfloat.h"
#include "libavutil/dict.h"
typedef struct {
    int64_t data;
    uint8_t *pkt_sizes;
    int size_buffer_size;
    int size_entries_used;
    int packets;
} CAFContext;

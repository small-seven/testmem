#define BITSTREAM_READER_LE
#include "libavutil/channel_layout.h"
#include "dcadec.h"
#include "dcadata.h"
#include "dcahuff.h"
#include "dca_syncwords.h"
#include "bytestream.h"
#define AMP_MAX     56
typedef struct LBRChunk {
    int id, len;
    const uint8_t *data;
} LBRChunk;

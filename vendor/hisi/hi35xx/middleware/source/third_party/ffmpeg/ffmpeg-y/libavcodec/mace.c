#include "avcodec.h"
#include "internal.h"
#include "libavutil/common.h"
#define QT_8S_2_16S(x) (((x) & 0xFF00) | (((x) >> 8) & 0xFF))
typedef struct ChannelData {
    int16_t index, factor, prev2, previous, level;
} ChannelData;
typedef struct MACEContext {
    ChannelData chd[2];
} MACEContext;

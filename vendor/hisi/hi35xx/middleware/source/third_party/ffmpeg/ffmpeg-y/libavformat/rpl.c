#include <inttypes.h>
#include <stdlib.h>
#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "internal.h"
#define RPL_SIGNATURE "ARMovie\x0A"
#define RPL_SIGNATURE_SIZE 8
#define RPL_LINE_LENGTH 256
typedef struct RPLContext {
    // RPL header data
    int32_t frames_per_chunk;

    // Stream position data
    uint32_t chunk_number;
    uint32_t chunk_part;
    uint32_t frame_in_part;
} RPLContext;
#if 0
#endif

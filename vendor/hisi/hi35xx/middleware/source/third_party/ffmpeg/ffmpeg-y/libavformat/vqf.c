#include "avformat.h"
#include "internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "riff.h"
typedef struct VqfContext {
    int frame_bit_len;
    uint8_t last_frame_bits;
    int remaining_bits;
} VqfContext;

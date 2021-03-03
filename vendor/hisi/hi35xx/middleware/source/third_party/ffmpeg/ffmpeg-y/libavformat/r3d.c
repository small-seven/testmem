#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "avformat.h"
#include "internal.h"
typedef struct R3DContext {
    unsigned video_offsets_count;
    unsigned *video_offsets;
    unsigned rdvo_offset;

    int audio_channels;
} R3DContext;
typedef struct Atom {
    unsigned size;
    uint32_t tag;
    uint64_t offset;
} Atom;
#if FF_API_R_FRAME_RATE
#endif

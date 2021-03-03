#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "riff.h"
#define DXA_EXTRA_SIZE  9
typedef struct DXAContext {
    int frames;
    int has_sound;
    int bpc;
    uint32_t bytes_left;
    int64_t wavpos, vidpos;
    int readvid;
}DXAContext;

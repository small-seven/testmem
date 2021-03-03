#include "libavutil/intreadwrite.h"
#include "libavcodec/internal.h"
#include "avformat.h"
#include "internal.h"
typedef struct GENHDemuxContext {
    unsigned dsp_int_type;
    unsigned interleave_size;
} GENHDemuxContext;

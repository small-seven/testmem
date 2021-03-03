#include "libavutil/channel_layout.h"
#include "libavutil/avassert.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct VolDetectContext {
    /**
     * Number of samples at each PCM value.
     * histogram[0x8000 + i] is the number of samples at value i.
     * The extra element is there for symmetry.
     */
    uint64_t histogram[0x10001];
} VolDetectContext;
#define MAX_DB 91

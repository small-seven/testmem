#include "libavutil/attributes.h"
#include "apetag.h"
#include "avformat.h"
#include "wv.h"
typedef struct WvMuxContext {
    int64_t samples;
} WvMuxContext;

#include "avformat.h"
#include "internal.h"
#include "libavutil/opt.h"
typedef struct G726Context {
    AVClass *class;
    int code_size;
    int sample_rate;
} G726Context;
#define OFFSET(x) offsetof(G726Context, x)
#if CONFIG_G726_DEMUXER
#endif
#if CONFIG_G726LE_DEMUXER
#endif

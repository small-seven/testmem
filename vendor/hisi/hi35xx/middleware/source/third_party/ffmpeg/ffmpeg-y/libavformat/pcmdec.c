#include "avformat.h"
#include "internal.h"
#include "pcm.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/avassert.h"
typedef struct PCMAudioDemuxerContext {
    AVClass *class;
    int sample_rate;
    int channels;
} PCMAudioDemuxerContext;
#define PCMDEF(name_, long_name_, ext, codec, ...)          \

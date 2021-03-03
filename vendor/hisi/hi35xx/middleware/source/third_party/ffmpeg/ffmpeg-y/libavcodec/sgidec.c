#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "sgi.h"
typedef struct SgiState {
    AVCodecContext *avctx;
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    unsigned int bytes_per_channel;
    int linesize;
    GetByteContext g;
} SgiState;

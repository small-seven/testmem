#include "libavutil/common.h"
#include "avcodec.h"
#include "bethsoftvideo.h"
#include "bytestream.h"
#include "internal.h"
typedef struct BethsoftvidContext {
    AVFrame *frame;
    GetByteContext g;
} BethsoftvidContext;

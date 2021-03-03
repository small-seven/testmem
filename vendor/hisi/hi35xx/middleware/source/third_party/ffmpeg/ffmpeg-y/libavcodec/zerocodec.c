#include <zlib.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/common.h"
typedef struct ZeroCodecContext {
    AVFrame  *previous_frame;
    z_stream zstream;
} ZeroCodecContext;

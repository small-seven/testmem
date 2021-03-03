#include <stdlib.h>
#include "libavutil/bswap.h"
#include "libavcodec/get_bits.h"
#include "avformat.h"
#include "internal.h"
#include "oggdec.h"
typedef struct TheoraParams {
    int gpshift;
    int gpmask;
    unsigned version;
} TheoraParams;

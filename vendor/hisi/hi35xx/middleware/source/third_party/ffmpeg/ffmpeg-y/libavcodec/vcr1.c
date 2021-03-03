#include "avcodec.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/internal.h"
typedef struct VCR1Context {
    int delta[16];
    int offset[4];
} VCR1Context;

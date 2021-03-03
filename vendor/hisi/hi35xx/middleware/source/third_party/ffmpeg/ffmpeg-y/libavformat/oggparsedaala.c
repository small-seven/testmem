#include <stdlib.h>
#include "libavcodec/bytestream.h"
#include "avformat.h"
#include "internal.h"
#include "oggdec.h"
typedef struct DaalaInfoHeader {
    int init_d;
    int fpr;
    int gpshift;
    int gpmask;
    int version_maj;
    int version_min;
    int version_sub;
    int frame_duration;
    int keyframe_granule_shift;
    struct DaalaPixFmtMap format;
} DaalaInfoHeader;

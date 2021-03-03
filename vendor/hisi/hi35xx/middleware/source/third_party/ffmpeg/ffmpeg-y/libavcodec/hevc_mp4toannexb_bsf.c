#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bsf.h"
#include "bytestream.h"
#include "hevc.h"
#define MIN_HEVCC_LENGTH 23
typedef struct HEVCBSFContext {
    uint8_t  length_size;
    int      extradata_parsed;
} HEVCBSFContext;

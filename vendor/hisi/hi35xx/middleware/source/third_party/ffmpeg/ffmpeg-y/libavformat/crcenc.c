#include <inttypes.h>
#include "libavutil/adler32.h"
#include "avformat.h"
typedef struct CRCState {
    uint32_t crcval;
} CRCState;

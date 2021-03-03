#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct ProSumerContext {
    GetByteContext gb;
    PutByteContext pb;

    unsigned stride;
    unsigned size;
    uint32_t lut[0x2000];
    uint8_t *initial_line;
    uint8_t *decbuffer;
} ProSumerContext;
#define PAIR(high, low) (((uint64_t)(high) << 32) | low)
#define TB(i) (1 + ((i) > 10) + ((i) > 49))

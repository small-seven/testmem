#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct TrueMotion2RTContext {
    GetBitContext gb;
    int delta_size;
    int hscale;
} TrueMotion2RTContext;

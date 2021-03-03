#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include <zlib.h>
typedef struct MWSCContext {
    unsigned int      decomp_size;
    uint8_t          *decomp_buf;
    z_stream          zstream;
    AVFrame          *prev_frame;
} MWSCContext;

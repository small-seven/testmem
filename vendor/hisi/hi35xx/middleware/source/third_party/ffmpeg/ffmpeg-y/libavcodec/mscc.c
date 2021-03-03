#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include <zlib.h>
typedef struct MSCCContext {
    unsigned          bpp;
    unsigned int      decomp_size;
    uint8_t          *decomp_buf;
    unsigned int      uncomp_size;
    uint8_t          *uncomp_buf;
    z_stream          zstream;

    uint32_t          pal[256];
} MSCCContext;

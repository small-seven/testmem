#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define BLOCK_HEIGHT 112u
#define BLOCK_WIDTH  84u
typedef struct InterBlock {
    int      w, h;
    int      size;
    int      xor;
} InterBlock;
typedef struct FMVCContext {
    GetByteContext  gb;
    PutByteContext  pb;
    uint8_t        *buffer;
    size_t          buffer_size;
    uint8_t        *pbuffer;
    size_t          pbuffer_size;
    ptrdiff_t       stride;
    int             bpp;
    int             yb, xb;
    InterBlock     *blocks;
    unsigned        nb_blocks;
} FMVCContext;

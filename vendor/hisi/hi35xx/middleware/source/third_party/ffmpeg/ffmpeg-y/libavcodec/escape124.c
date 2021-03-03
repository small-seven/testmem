#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef union MacroBlock {
    uint16_t pixels[4];
    uint32_t pixels32[2];
} MacroBlock;
typedef union SuperBlock {
    uint16_t pixels[64];
    uint32_t pixels32[32];
} SuperBlock;
typedef struct CodeBook {
    unsigned depth;
    unsigned size;
    MacroBlock* blocks;
} CodeBook;
typedef struct Escape124Context {
    AVFrame *frame;

    unsigned num_superblocks;

    CodeBook codebooks[3];
} Escape124Context;

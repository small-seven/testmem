#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "avcodec.h"
#include "blockdsp.h"
#include "internal.h"
#include "get_bits.h"
#include "bytestream.h"
#include "bswapdsp.h"
#include "hpeldsp.h"
#include "idctdsp.h"
#include "thread.h"
#define MIMIC_HEADER_SIZE   20
typedef struct MimicContext {
    AVCodecContext *avctx;

    int             num_vblocks[3];
    int             num_hblocks[3];

    void           *swap_buf;
    int             swap_buf_size;

    int             cur_index;
    int             prev_index;

    ThreadFrame     frames     [16];

    DECLARE_ALIGNED(32, int16_t, dct_block)[64];

    GetBitContext   gb;
    ScanTable       scantable;
    BlockDSPContext bdsp;
    BswapDSPContext bbdsp;
    HpelDSPContext  hdsp;
    IDCTDSPContext  idsp;
    VLC             vlc;

    /* Kept in the context so multithreading can have a constant to read from */
    int             next_cur_index;
    int             next_prev_index;
} MimicContext;
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif

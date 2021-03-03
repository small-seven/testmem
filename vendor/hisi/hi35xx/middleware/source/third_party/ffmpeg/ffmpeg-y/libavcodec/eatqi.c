#include "avcodec.h"
#include "blockdsp.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "aandcttab.h"
#include "eaidct.h"
#include "idctdsp.h"
#include "internal.h"
#include "mpeg12.h"
typedef struct TqiContext {
    AVCodecContext *avctx;
    GetBitContext gb;
    BlockDSPContext bdsp;
    BswapDSPContext bsdsp;
    IDCTDSPContext idsp;
    ScanTable intra_scantable;

    void *bitstream_buf;
    unsigned int bitstream_buf_size;

    int mb_x, mb_y;
    uint16_t intra_matrix[64];
    int last_dc[3];

    DECLARE_ALIGNED(32, int16_t, block)[6][64];
} TqiContext;

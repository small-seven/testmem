#include "avcodec.h"
#include "blockdsp.h"
#include "bswapdsp.h"
#include "idctdsp.h"
#include "mpeg12.h"
#include "thread.h"
typedef struct MDECContext {
    AVCodecContext *avctx;
    BlockDSPContext bdsp;
    BswapDSPContext bbdsp;
    IDCTDSPContext idsp;
    ThreadFrame frame;
    GetBitContext gb;
    ScanTable scantable;
    int version;
    int qscale;
    int last_dc[3];
    int mb_width;
    int mb_height;
    int mb_x, mb_y;
    DECLARE_ALIGNED(32, int16_t, block)[6][64];
    DECLARE_ALIGNED(16, uint16_t, quant_matrix)[64];
    uint8_t *bitstream_buffer;
    unsigned int bitstream_buffer_size;
    int block_last_index[6];
} MDECContext;
#if HAVE_THREADS
#endif

#include "avcodec.h"
#include "blockdsp.h"
#include "bytestream.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "aandcttab.h"
#include "eaidct.h"
#include "idctdsp.h"
#include "internal.h"
#include "mpeg12data.h"
#include "mpeg12vlc.h"
#define EA_PREAMBLE_SIZE    8
#define MADk_TAG MKTAG('M', 'A', 'D', 'k')    /* MAD I-frame */
#define MADm_TAG MKTAG('M', 'A', 'D', 'm')    /* MAD P-frame */
#define MADe_TAG MKTAG('M', 'A', 'D', 'e')    /* MAD lqp-frame */
typedef struct MadContext {
    AVCodecContext *avctx;
    BlockDSPContext bdsp;
    BswapDSPContext bbdsp;
    IDCTDSPContext idsp;
    AVFrame *last_frame;
    GetBitContext gb;
    void *bitstream_buf;
    unsigned int bitstream_buf_size;
    DECLARE_ALIGNED(32, int16_t, block)[64];
    ScanTable scantable;
    uint16_t quant_matrix[64];
    int mb_x;
    int mb_y;
} MadContext;

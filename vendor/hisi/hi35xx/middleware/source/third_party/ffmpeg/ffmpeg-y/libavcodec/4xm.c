#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/frame.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#define BLOCK_TYPE_VLC_BITS 5
#define ACDC_VLC_BITS 9
#define CFRAME_BUFFER_COUNT 100
typedef struct CFrameBuffer {
    unsigned int allocated_size;
    unsigned int size;
    int id;
    uint8_t *data;
} CFrameBuffer;
typedef struct FourXContext {
    AVCodecContext *avctx;
    BlockDSPContext bdsp;
    BswapDSPContext bbdsp;
    uint16_t *frame_buffer;
    uint16_t *last_frame_buffer;
    GetBitContext pre_gb;          ///< ac/dc prefix
    GetBitContext gb;
    GetByteContext g;
    GetByteContext g2;
    int mv[256];
    VLC pre_vlc;
    int last_dc;
    DECLARE_ALIGNED(32, int16_t, block)[6][64];
    void *bitstream_buffer;
    unsigned int bitstream_buffer_size;
    int version;
    CFrameBuffer cfrm[CFRAME_BUFFER_COUNT];
} FourXContext;
#define FIX_1_082392200  70936
#define FIX_1_414213562  92682
#define FIX_1_847759065 121095
#define FIX_2_613125930 171254
#define MULTIPLY(var, const) ((int)((var) * (unsigned)(const)) >> 16)
#if HAVE_BIGENDIAN
#define LE_CENTRIC_MUL(dst, src, scale, dc)             \
#else
#define LE_CENTRIC_MUL(dst, src, scale, dc)              \
#endif

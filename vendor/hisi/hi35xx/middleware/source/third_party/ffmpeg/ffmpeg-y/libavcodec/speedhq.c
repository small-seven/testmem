#define BITSTREAM_READER_LE
#include "libavutil/attributes.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "libavutil/thread.h"
#include "mathops.h"
#include "mpeg12.h"
#include "mpeg12data.h"
#include "mpeg12vlc.h"
#define MAX_INDEX (64 - 1)
#define ALPHA_VLC_BITS 5
typedef struct SHQContext {
    AVCodecContext *avctx;
    BlockDSPContext bdsp;
    IDCTDSPContext idsp;
    ScanTable intra_scantable;
    int quant_matrix[64];
    enum { SHQ_SUBSAMPLING_420, SHQ_SUBSAMPLING_422, SHQ_SUBSAMPLING_444 }
#if MIN_CACHE_BITS < 6 + 6 + 12
#error MIN_CACHE_BITS is too small for the escape code, add UPDATE_CACHE
#endif

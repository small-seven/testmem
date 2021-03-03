#include "libavutil/imgutils.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "lossless_videodsp.h"
#include "mathops.h"
#include "thread.h"
typedef struct VBLEContext {
    AVCodecContext *avctx;
    LLVidDSPContext llviddsp;

    int            size;
    uint8_t        *val; ///< This array first holds the lengths of vlc symbols and then their value.
} VBLEContext;

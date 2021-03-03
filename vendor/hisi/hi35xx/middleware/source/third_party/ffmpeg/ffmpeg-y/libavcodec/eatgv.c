#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#define EA_PREAMBLE_SIZE    8
#define kVGT_TAG MKTAG('k', 'V', 'G', 'T')
typedef struct TgvContext {
    AVCodecContext *avctx;
    AVFrame *last_frame;
    uint8_t *frame_buffer;
    int width,height;
    uint32_t palette[AVPALETTE_COUNT];

    int (*mv_codebook)[2];
    uint8_t (*block_codebook)[16];
    int num_mvs;           ///< current length of mv_codebook
    int num_blocks_packed; ///< current length of block_codebook
} TgvContext;

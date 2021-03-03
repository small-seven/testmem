#include "avcodec.h"
#include "get_bits.h"
#include "bswapdsp.h"
#include "internal.h"
#define MAX_HUFF_CODES 16
#include "motionpixels_tablegen.h"
typedef struct HuffCode {
    int code;
    uint8_t size;
    uint8_t delta;
} HuffCode;
typedef struct MotionPixelsContext {
    AVCodecContext *avctx;
    AVFrame *frame;
    BswapDSPContext bdsp;
    uint8_t *changes_map;
    int offset_bits_len;
    int codes_count, current_codes_count;
    int max_codes_bits;
    HuffCode codes[MAX_HUFF_CODES];
    VLC vlc;
    YuvPixel *vpt, *hpt;
    uint8_t gradient_scale[3];
    uint8_t *bswapbuf;
    int bswapbuf_size;
} MotionPixelsContext;

#define UNCHECKED_BITSTREAM_READER 1
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#define BIT_PLANAR   0x00
#define CHUNKY       0x20
#define BYTE_PLANAR  0x40
#define BIT_LINE     0x80
#define BYTE_LINE    0xC0
typedef struct CDXLVideoContext {
    AVCodecContext *avctx;
    int            bpp;
    int            format;
    int            padded_bits;
    const uint8_t  *palette;
    int            palette_size;
    const uint8_t  *video;
    int            video_size;
    uint8_t        *new_video;
    int            new_video_size;
} CDXLVideoContext;

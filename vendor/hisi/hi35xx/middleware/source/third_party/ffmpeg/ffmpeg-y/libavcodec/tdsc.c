#include <stdint.h>
#include <zlib.h>
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define BITMAPINFOHEADER_SIZE 0x28
#define TDSF_HEADER_SIZE      0x56
#define TDSB_HEADER_SIZE      0x08
typedef struct TDSCContext {
    AVCodecContext *jpeg_avctx;   // wrapper context for MJPEG

    int width, height;
    GetByteContext gbc;

    AVFrame *refframe;          // full decoded frame (without cursor)
    AVFrame *jpgframe;          // decoded JPEG tile
    uint8_t *tilebuffer;        // buffer containing tile data

    /* zlib interaction */
    uint8_t *deflatebuffer;
    uLongf deflatelen;

    /* All that is cursor */
    uint8_t    *cursor;
    int        cursor_stride;
    int        cursor_w, cursor_h, cursor_x, cursor_y;
    int        cursor_hot_x, cursor_hot_y;
} TDSCContext;
#define APPLY_ALPHA(src, new, alpha) \

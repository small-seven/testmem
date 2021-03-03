#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "lzw.h"
#include "gif.h"
#define GIF_TRANSPARENT_COLOR    0x00ffffff
typedef struct GifState {
    const AVClass *class;
    AVFrame *frame;
    int screen_width;
    int screen_height;
    int has_global_palette;
    int bits_per_pixel;
    uint32_t bg_color;
    int background_color_index;
    int transparent_color_index;
    int color_resolution;
    /* intermediate buffer for storing color indices
     * obtained from lzw-encoded data stream */
    uint8_t *idx_line;
    int idx_line_size;

    /* after the frame is displayed, the disposal method is used */
    int gce_prev_disposal;
    int gce_disposal;
    /* rectangle describing area that must be disposed */
    int gce_l, gce_t, gce_w, gce_h;
    /* depending on disposal method we store either part of the image
     * drawn on the canvas or background color that
     * should be used upon disposal */
    uint32_t * stored_img;
    int stored_img_size;
    int stored_bg_color;

    GetByteContext gb;
    LZWState *lzw;

    /* aux buffers */
    uint32_t global_palette[256];
    uint32_t local_palette[256];

    AVCodecContext *avctx;
    int keyframe;
    int keyframe_ok;
    int trans_color;    /**< color value that is used instead of transparent color */
} GifState;
#if FF_API_PKT_PTS
#endif

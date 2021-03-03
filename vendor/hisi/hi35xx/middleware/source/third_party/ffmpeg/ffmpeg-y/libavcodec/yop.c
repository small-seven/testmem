#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
typedef struct YopDecContext {
    AVCodecContext *avctx;
    AVFrame *frame;

    int num_pal_colors;
    int first_color[2];
    int frame_data_length;

    uint8_t *low_nibble;
    uint8_t *srcptr;
    uint8_t *src_end;
    uint8_t *dstptr;
    uint8_t *dstbuf;
} YopDecContext;

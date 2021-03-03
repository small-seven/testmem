#include "avcodec.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "mjpegdec.h"
#include "internal.h"
typedef struct SMVJpegDecodeContext {
    MJpegDecodeContext jpg;
    AVFrame *picture[2]; /* pictures array */
    AVCodecContext* avctx;
    int frames_per_jpeg;
    int mjpeg_data_size;
} SMVJpegDecodeContext;

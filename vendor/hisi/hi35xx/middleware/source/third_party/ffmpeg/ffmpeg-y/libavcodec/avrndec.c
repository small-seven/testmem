#include "avcodec.h"
#include "internal.h"
#include "mjpeg.h"
#include "mjpegdec.h"
#include "libavutil/imgutils.h"
typedef struct {
    AVCodecContext *mjpeg_avctx;
    int is_mjpeg;
    int interlace;
    int tff;
} AVRnContext;

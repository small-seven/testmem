#include <stdint.h>
#include <string.h>
#include <mfx/mfxvideo.h>
#include "libavutil/common.h"
#include "libavutil/fifo.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "qsv_internal.h"
#include "qsvdec.h"
#include "qsv.h"
typedef struct QSVOtherContext {
    AVClass *class;
    QSVContext qsv;

    AVFifoBuffer *packet_fifo;

    AVPacket input_ref;
} QSVOtherContext;
#if CONFIG_VP8_QSV_DECODER
#endif
#if CONFIG_VP8_QSV_DECODER
#endif
#define OFFSET(x) offsetof(QSVOtherContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_MPEG2_QSV_DECODER
#endif
#if CONFIG_VC1_QSV_DECODER
#endif
#if CONFIG_VP8_QSV_DECODER
#endif

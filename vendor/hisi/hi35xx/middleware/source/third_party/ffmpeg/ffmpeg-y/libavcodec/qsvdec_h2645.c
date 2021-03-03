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
typedef struct QSVH2645Context {
    AVClass *class;
    QSVContext qsv;

    int load_plugin;

    AVFifoBuffer *packet_fifo;

    AVPacket buffer_pkt;
} QSVH2645Context;
#define OFFSET(x) offsetof(QSVH2645Context, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_HEVC_QSV_DECODER
#endif
#if CONFIG_H264_QSV_DECODER
#endif

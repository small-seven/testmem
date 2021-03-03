#include <stdint.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "av1.h"
#include "av1_parse.h"
#include "bsf.h"
#include "h2645_parse.h"
#include "h264.h"
#include "hevc.h"
#include "vc1_common.h"
typedef struct ExtractExtradataContext {
    const AVClass *class;

    int (*extract)(AVBSFContext *ctx, AVPacket *pkt,
                   uint8_t **data, int *size);

    /* AV1 specifc fields */
    AV1Packet av1_pkt;

    /* H264/HEVC specifc fields */
    H2645Packet h2645_pkt;

    /* AVOptions */
    int remove;
} ExtractExtradataContext;
#define OFFSET(x) offsetof(ExtractExtradataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)

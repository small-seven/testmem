#include <stdint.h>
#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/pixfmt.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "decode.h"
#include "h264_parse.h"
#include "hevc_parse.h"
#include "hwaccel.h"
#include "internal.h"
#include "mediacodec_wrapper.h"
#include "mediacodecdec_common.h"
typedef struct MediaCodecH264DecContext {

    AVClass *avclass;

    MediaCodecDecContext *ctx;

    AVPacket buffered_pkt;

    int delay_flush;
    int amlogic_mpeg2_api23_workaround;

} MediaCodecH264DecContext;
#if CONFIG_H264_MEDIACODEC_DECODER || CONFIG_HEVC_MEDIACODEC_DECODER
#endif
#if CONFIG_H264_MEDIACODEC_DECODER
#endif
#if CONFIG_HEVC_MEDIACODEC_DECODER
#endif
#if CONFIG_MPEG2_MEDIACODEC_DECODER || \
#endif
#if CONFIG_H264_MEDIACODEC_DECODER
#endif
#if CONFIG_HEVC_MEDIACODEC_DECODER
#endif
#if CONFIG_MPEG2_MEDIACODEC_DECODER
#endif
#if CONFIG_MPEG4_MEDIACODEC_DECODER
#endif
#if CONFIG_VP8_MEDIACODEC_DECODER
#endif
#if CONFIG_VP9_MEDIACODEC_DECODER
#endif
#define OFFSET(x) offsetof(MediaCodecH264DecContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#define DECLARE_MEDIACODEC_VCLASS(short_name)                   \
#define DECLARE_MEDIACODEC_VDEC(short_name, full_name, codec_id, bsf)                          \
#if CONFIG_H264_MEDIACODEC_DECODER
#endif
#if CONFIG_HEVC_MEDIACODEC_DECODER
#endif
#if CONFIG_MPEG2_MEDIACODEC_DECODER
#endif
#if CONFIG_MPEG4_MEDIACODEC_DECODER
#endif
#if CONFIG_VP8_MEDIACODEC_DECODER
#endif
#if CONFIG_VP9_MEDIACODEC_DECODER
#endif

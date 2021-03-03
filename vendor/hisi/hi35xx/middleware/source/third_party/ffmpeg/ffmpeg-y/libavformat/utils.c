#include <stdarg.h>
#include <stdint.h>
#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/thread.h"
#include "libavutil/time.h"
#include "libavutil/time_internal.h"
#include "libavutil/timestamp.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/internal.h"
#include "libavcodec/raw.h"
#include "audiointerleave.h"
#include "avformat.h"
#include "avio_internal.h"
#include "id3v2.h"
#include "internal.h"
#include "metadata.h"
#if CONFIG_NETWORK
#include "network.h"
#endif
#include "riff.h"
#include "url.h"
#include "libavutil/ffversion.h"
#define LICENSE_PREFIX "libavformat license: "
#define RELATIVE_TS_BASE (INT64_MAX - (1LL<<48))
#if FF_API_FORMAT_GET_SET
#if FF_API_LAVF_FFSERVER
#endif
#if FF_API_OLD_OPEN_CALLBACKS
#endif
#endif
#if FF_API_LAVF_AVCTX
#endif
#if CONFIG_H264_DECODER
#endif
#if FF_API_FORMAT_GET_SET
#endif
#define SANE_CHUNK_SIZE (50000000)
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_FORMAT_FILENAME
#endif
#if FF_API_LAVF_AVCTX
#endif
#if CONFIG_H264_DECODER
#endif
#if FF_API_CONVERGENCE_DURATION
#endif
void ff_packet_list_free(AVPacketList **pkt_buf, AVPacketList **pkt_buf_end)
{
    AVPacketList *tmp = *pkt_buf;

    while (tmp) {
        AVPacketList *pktl = tmp;
        tmp = pktl->next;
        av_packet_unref(&pktl->pkt);
        av_freep(&pktl);
    }
    *pkt_buf     = NULL;
    *pkt_buf_end = NULL;
}
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if 0
#endif
#define DURATION_MAX_READ_SIZE 250000LL
#define DURATION_MAX_RETRY 6
#define FAIL(errmsg) do {                                         \
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_R_FRAME_RATE
#endif
#if FF_API_R_FRAME_RATE
#endif
#if FF_API_LOWRES
#endif
#if FF_API_LAVF_AVCTX
#if FF_API_LOWRES
#endif
#endif
#if FF_API_LAVF_FFSERVER
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_FFSERVER
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_R_FRAME_RATE
#endif
#if FF_API_LAVF_AVCTX
#endif
#if CONFIG_NETWORK
#endif
#if CONFIG_NETWORK
#endif
#if FF_API_LAVF_AVCTX
#else
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#else
#endif
#if FF_API_OLD_BSF
#endif
#if FF_API_R_FRAME_RATE
#endif
#if FF_API_LAVF_AVCTX
#else
#endif
#if FF_API_FORMAT_FILENAME
#endif

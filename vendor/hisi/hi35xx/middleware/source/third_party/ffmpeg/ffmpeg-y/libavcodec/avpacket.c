#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#if FF_API_CONVERGENCE_DURATION
#endif
void av_packet_free(AVPacket **pkt)
{
    if (!pkt || !*pkt)
        return;

    av_packet_unref(*pkt);
    av_freep(pkt);
}
#if FF_API_AVPACKET_OLD_API
#define ALLOC_MALLOC(data, size) data = av_malloc(size)
#define ALLOC_BUF(data, size)                \
#define DUP_DATA(dst, src, size, padding, ALLOC)                        \
#endif
#if FF_API_AVPACKET_OLD_API
#endif
#if FF_API_MERGE_SD_API
#define FF_MERGE_MARKER 0x8c4d9d108e25e9feULL
#endif
#if FF_API_CONVERGENCE_DURATION
#endif
#if FF_API_CONVERGENCE_DURATION
#endif

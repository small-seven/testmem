#include "libavcodec/bytestream.h"
#include "libavutil/avstring.h"
#include "libavutil/intfloat.h"
#include "avformat.h"
#include "rtmppkt.h"
#include "flv.h"
#include "url.h"
void ff_rtmp_packet_destroy(RTMPPacket *pkt)
{
    if (!pkt)
        return;
    av_freep(&pkt->data);
    pkt->size = 0;
}

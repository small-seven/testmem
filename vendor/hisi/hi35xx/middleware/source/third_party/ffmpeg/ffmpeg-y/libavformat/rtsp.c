#include "libavutil/avassert.h"
#include "libavutil/base64.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/parseutils.h"
#include "libavutil/random_seed.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "avformat.h"
#include "avio_internal.h"
#if HAVE_POLL_H
#include <poll.h>
#endif
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "http.h"
#include "rtsp.h"
#include "rtpdec.h"
#include "rtpproto.h"
#include "rdt.h"
#include "rtpdec_formats.h"
#include "rtpenc_chain.h"
#include "url.h"
#include "rtpenc.h"
#include "mpegts.h"
#define POLL_TIMEOUT_MS 100
#define READ_PACKET_TIMEOUT_S 10
#define MAX_TIMEOUTS READ_PACKET_TIMEOUT_S * 1000 / POLL_TIMEOUT_MS
#define SDP_MAX_SIZE 16384
#define RECVBUF_SIZE 10 * RTP_MAX_PACKET_LENGTH
#define DEFAULT_REORDERING_DELAY 100000
#define OFFSET(x) offsetof(RTSPState, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#define RTSP_FLAG_OPTS(name, longname) \
#define RTSP_MEDIATYPE_OPTS(name, longname) \
#define COMMON_OPTS() \
#if FF_API_OLD_RTSP_OPTIONS
#else
#endif
#if FF_API_OLD_RTSP_OPTIONS
#endif
#if CONFIG_RTPDEC
typedef struct SDPParseState {
    /* SDP only */
    struct sockaddr_storage default_ip;
    int            default_ttl;
    int            skip_media;  ///< set if an unknown m= line occurs
    int nb_default_include_source_addrs; /**< Number of source-specific multicast include source IP address (from SDP content) */
    struct RTSPSource **default_include_source_addrs; /**< Source-specific multicast include source IP address (from SDP content) */
    int nb_default_exclude_source_addrs; /**< Number of source-specific multicast exclude source IP address (from SDP content) */
    struct RTSPSource **default_exclude_source_addrs; /**< Source-specific multicast exclude source IP address (from SDP content) */
    int seen_rtpmap;
    int seen_fmtp;
    char delayed_fmtp[2048];
} SDPParseState;
#endif /* CONFIG_RTPDEC */
#if CONFIG_RTSP_DEMUXER || CONFIG_RTSP_MUXER
#endif /* CONFIG_RTSP_DEMUXER || CONFIG_RTSP_MUXER */
#if CONFIG_RTPDEC
#if CONFIG_RTSP_DEMUXER
#endif
#if CONFIG_RTSP_DEMUXER
#endif
#endif /* CONFIG_RTPDEC */
#if CONFIG_SDP_DEMUXER
#endif /* CONFIG_SDP_DEMUXER */
#if CONFIG_RTP_DEMUXER
#endif /* CONFIG_RTP_DEMUXER */

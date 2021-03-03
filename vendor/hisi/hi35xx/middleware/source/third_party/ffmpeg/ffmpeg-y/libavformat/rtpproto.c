#include "libavutil/parseutils.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "avio_internal.h"
#include "rtp.h"
#include "rtpproto.h"
#include "url.h"
#include "ip.h"
#include <stdarg.h>
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include <fcntl.h>
#if HAVE_POLL_H
#include <poll.h>
#endif
typedef struct RTPContext {
    const AVClass *class;
    URLContext *rtp_hd, *rtcp_hd, *fec_hd;
    int rtp_fd, rtcp_fd;
    IPSourceFilters filters;
    int write_to_source;
    struct sockaddr_storage last_rtp_source, last_rtcp_source;
    socklen_t last_rtp_source_len, last_rtcp_source_len;
    int ttl;
    int buffer_size;
    int rtcp_port, local_rtpport, local_rtcpport;
    int connect;
    int pkt_size;
    int dscp;
    char *sources;
    char *block;
    char *fec_options_str;
} RTPContext;
#define OFFSET(x) offsetof(RTPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
#if HAVE_STRUCT_SOCKADDR_IN6
#endif
#if HAVE_STRUCT_SOCKADDR_IN6
#endif

#include "avformat.h"
#include "libavutil/avassert.h"
#include "libavutil/parseutils.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#if HAVE_POLL_H
#include <poll.h>
#endif
typedef struct TCPContext {
    const AVClass *class;
    int fd;
    int listen;
    int open_timeout;
    int rw_timeout;
    int listen_timeout;
    int recv_buffer_size;
    int send_buffer_size;
    int tcp_nodelay;
#if !HAVE_WINSOCK2_H
    int tcp_mss;
#endif /* !HAVE_WINSOCK2_H */
} TCPContext;
#define OFFSET(x) offsetof(TCPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
#if !HAVE_WINSOCK2_H
#endif /* !HAVE_WINSOCK2_H */
#if !HAVE_WINSOCK2_H
#endif /* !HAVE_WINSOCK2_H */
#if HAVE_STRUCT_SOCKADDR_IN6
#endif
#if HAVE_WINSOCK2_H
#endif

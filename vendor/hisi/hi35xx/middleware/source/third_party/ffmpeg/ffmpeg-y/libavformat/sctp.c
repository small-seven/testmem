#include <netinet/in.h>
#include <netinet/sctp.h>
#include "config.h"
#if HAVE_POLL_H
#include <poll.h>
#endif
#include "libavutil/intreadwrite.h"
#include "libavutil/parseutils.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
typedef struct SCTPContext {
    const AVClass *class;
    int fd;
    int listen;
    int timeout;
    int listen_timeout;
    int max_streams;
    struct sockaddr_storage dest_addr;
} SCTPContext;
#define OFFSET(x) offsetof(SCTPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM

#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "os_support.h"
#include "network.h"
#include <sys/un.h>
#include "url.h"
typedef struct UnixContext {
    const AVClass *class;
    struct sockaddr_un addr;
    int timeout;
    int listen;
    int type;
    int fd;
} UnixContext;
#define OFFSET(x) offsetof(UnixContext, x)
#define ED AV_OPT_FLAG_DECODING_PARAM|AV_OPT_FLAG_ENCODING_PARAM

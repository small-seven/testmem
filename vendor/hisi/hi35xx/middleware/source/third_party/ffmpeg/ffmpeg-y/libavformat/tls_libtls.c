#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "url.h"
#include "tls.h"
#include "libavcodec/internal.h"
#include "libavutil/avutil.h"
#include "libavutil/opt.h"
#include <tls.h>
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;
    struct tls *ctx;
} TLSContext;

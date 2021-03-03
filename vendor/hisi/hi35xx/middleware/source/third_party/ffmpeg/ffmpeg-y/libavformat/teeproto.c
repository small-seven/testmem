#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "avio_internal.h"
#include "tee_common.h"
typedef struct ChildContext {
    URLContext *url_context;
} ChildContext;
typedef struct TeeContext {
    const AVClass *class;
    int child_count;
    ChildContext *child;
} TeeContext;

#include "libavutil/avstring.h"
#include "avformat.h"
#include "internal.h"
#include "network.h"
#include "url.h"
typedef struct GopherContext {
    URLContext *hd;
} GopherContext;

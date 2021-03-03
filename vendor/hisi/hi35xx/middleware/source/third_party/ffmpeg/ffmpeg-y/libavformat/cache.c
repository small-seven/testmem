#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/tree.h"
#include "avformat.h"
#include <fcntl.h>
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <sys/stat.h>
#include <stdlib.h>
#include "os_support.h"
#include "url.h"
typedef struct CacheEntry {
    int64_t logical_pos;
    int64_t physical_pos;
    int size;
} CacheEntry;
typedef struct Context {
    AVClass *class;
    int fd;
    char *filename;
    struct AVTreeNode *root;
    int64_t logical_pos;
    int64_t cache_pos;
    int64_t inner_pos;
    int64_t end;
    int is_true_eof;
    URLContext *inner;
    int64_t cache_hit, cache_miss;
    int read_ahead_limit;
} Context;
static int enu_free(void *opaque, void *elem)
{
    av_free(elem);
    return 0;
}
#define OFFSET(x) offsetof(Context, x)
#define D AV_OPT_FLAG_DECODING_PARAM

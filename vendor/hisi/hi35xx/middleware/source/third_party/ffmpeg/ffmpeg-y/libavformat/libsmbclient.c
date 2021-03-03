#include <libsmbclient.h>
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "url.h"
typedef struct {
    const AVClass *class;
    SMBCCTX *ctx;
    int dh;
    int fd;
    int64_t filesize;
    int trunc;
    int timeout;
    char *workgroup;
} LIBSMBContext;
#define OFFSET(x) offsetof(LIBSMBContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM

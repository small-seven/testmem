#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "url.h"
typedef struct SubfileContext {
    const AVClass *class;
    URLContext *h;
    int64_t start;
    int64_t end;
    int64_t pos;
} SubfileContext;
#define OFFSET(field) offsetof(SubfileContext, field)
#define D AV_OPT_FLAG_DECODING_PARAM
#undef OFFSET
#undef D

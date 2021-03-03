#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "ast.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
typedef struct ASTMuxContext {
    AVClass *class;
    int64_t  size;
    int64_t  samples;
    int64_t  loopstart;
    int64_t  loopend;
    int      fbs;
} ASTMuxContext;
#define CHECK_LOOP(type) \
#define OFFSET(obj) offsetof(ASTMuxContext, obj)

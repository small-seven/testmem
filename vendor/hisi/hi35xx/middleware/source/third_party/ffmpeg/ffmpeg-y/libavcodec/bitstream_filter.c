#include <string.h>
#include "avcodec.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#if FF_API_OLD_BSF
typedef struct BSFCompatContext {
    AVBSFContext *ctx;
    int extradata_updated;
} BSFCompatContext;
#endif

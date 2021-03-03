#include <stdio.h>
#include <stdlib.h>
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "lcl.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include <zlib.h>
typedef struct LclEncContext {

    AVCodecContext *avctx;

    // Image type
    int imgtype;
    // Compression type
    int compression;
    // Flags
    int flags;
    z_stream zstream;
} LclEncContext;
#if FF_API_CODED_FRAME
#endif

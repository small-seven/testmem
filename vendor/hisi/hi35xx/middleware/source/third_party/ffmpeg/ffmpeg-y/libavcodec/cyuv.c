#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/internal.h"
typedef struct CyuvDecodeContext {
    AVCodecContext *avctx;
    int width, height;
} CyuvDecodeContext;
#if CONFIG_AURA_DECODER
#endif
#if CONFIG_CYUV_DECODER
#endif

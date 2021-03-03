#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "sheervideodata.h"
typedef struct SheerVideoContext {
    unsigned format;
    int alt;
    VLC vlc[2];
    void (*decode_frame)(AVCodecContext *avctx, AVFrame *p, GetBitContext *gb);
} SheerVideoContext;
#if HAVE_THREADS
#endif

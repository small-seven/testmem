#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include <zlib.h>
typedef struct WCMVContext {
    int         bpp;
    z_stream    zstream;
    AVFrame    *prev_frame;
    uint8_t     block_data[65536*8];
} WCMVContext;

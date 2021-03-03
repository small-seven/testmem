#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct ARBCContext {
    GetByteContext gb;

    AVFrame *prev_frame;
} ARBCContext;

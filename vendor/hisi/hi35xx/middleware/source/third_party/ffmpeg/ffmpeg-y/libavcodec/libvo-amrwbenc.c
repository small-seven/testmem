#include <vo-amrwbenc/enc_if.h>
#include <stdio.h>
#include <stdlib.h>
#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#define MAX_PACKET_SIZE  (1 + (477 + 7) / 8)
typedef struct AMRWBContext {
    AVClass *av_class;
    void  *state;
    int    mode;
    int    last_bitrate;
    int    allow_dtx;
} AMRWBContext;

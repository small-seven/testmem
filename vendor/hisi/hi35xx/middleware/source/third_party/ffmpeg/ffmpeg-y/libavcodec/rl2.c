#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "internal.h"
#define EXTRADATA1_SIZE (6 + 256 * 3) ///< video base, clr count, palette
typedef struct Rl2Context {
    AVCodecContext *avctx;

    uint16_t video_base;  ///< initial drawing offset
    uint32_t clr_count;   ///< number of used colors (currently unused)
    uint8_t *back_frame;  ///< background frame
    uint32_t palette[AVPALETTE_COUNT];
} Rl2Context;

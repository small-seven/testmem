#include <stdint.h>
#include <string.h>
#include <zlib.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "internal.h"
typedef struct ScreenpressoContext {
    AVFrame *current;

    /* zlib interaction */
    uint8_t *inflated_buf;
    uLongf inflated_size;
} ScreenpressoContext;

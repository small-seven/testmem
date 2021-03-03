#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "internal.h"
typedef struct KgvContext {
    uint16_t *frame_buffer;
    uint16_t *last_frame_buffer;
} KgvContext;

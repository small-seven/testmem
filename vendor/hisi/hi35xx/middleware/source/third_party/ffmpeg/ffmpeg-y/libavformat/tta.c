#include "libavutil/crc.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "apetag.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "id3v1.h"
typedef struct TTAContext {
    int totalframes, currentframe;
    int frame_size;
    int last_frame_size;
} TTAContext;

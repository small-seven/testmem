#include "avformat.h"
#include "internal.h"
#include "isom.h"
#include "libavcodec/mpeg4audio.h"
#include "libavcodec/mpegaudiodata.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#if FF_API_LAVF_AVCTX
#endif
typedef struct MovChannelLayout {
    int64_t  channel_layout;
    uint32_t layout_tag;
} MovChannelLayout;
#if 0
#endif

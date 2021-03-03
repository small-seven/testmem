#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "internal.h"
#include "apetag.h"
#include "id3v1.h"
#include "wv.h"
typedef struct WVContext {
    uint8_t block_header[WV_HEADER_SIZE];
    WvHeader header;
    int rate, chan, bpp;
    uint32_t chmask;
    int multichannel;
    int block_parsed;
    int64_t pos;

    int64_t apetag_start;
} WVContext;

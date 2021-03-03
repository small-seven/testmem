#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
typedef struct SIFFContext {
    int frames;
    int cur_frame;
    int rate;
    int bits;
    int block_align;

    int has_video;
    int has_audio;

    int curstrm;
    unsigned int pktsize;
    int gmcsize;
    unsigned int sndsize;

    unsigned int flags;
    uint8_t gmc[4];
} SIFFContext;

#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/parseutils.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#define CDXL_HEADER_SIZE 32
typedef struct CDXLDemuxContext {
    AVClass     *class;
    int         sample_rate;
    char        *framerate;
    AVRational  fps;
    int         read_chunk;
    uint8_t     header[CDXL_HEADER_SIZE];
    int         video_stream_index;
    int         audio_stream_index;
    int64_t     filesize;
} CDXLDemuxContext;
#define OFFSET(x) offsetof(CDXLDemuxContext, x)

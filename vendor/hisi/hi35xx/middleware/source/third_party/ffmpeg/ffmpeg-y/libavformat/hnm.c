#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define HNM4_TAG MKTAG('H', 'N', 'M', '4')
#define HNM4_SAMPLE_RATE 22050
#define HNM4_FRAME_FPS 24
#define HNM4_CHUNK_ID_PL 19536
#define HNM4_CHUNK_ID_IZ 23113
#define HNM4_CHUNK_ID_IU 21833
#define HNM4_CHUNK_ID_SD 17491
typedef struct Hnm4DemuxContext {
    uint8_t version;
    uint16_t width;
    uint16_t height;
    uint32_t filesize;
    uint32_t frames;
    uint32_t taboffset;
    uint16_t bits;
    uint16_t channels;
    uint32_t framesize;
    uint32_t currentframe;
    int64_t pts;
    uint32_t superchunk_remaining;
    AVPacket vpkt;
} Hnm4DemuxContext;

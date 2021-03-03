#include "parser.h"
#include "mpegaudiodecheader.h"
#include "libavutil/common.h"
#include "libavformat/apetag.h" // for APE tag.
#include "libavformat/id3v1.h" // for ID3v1_TAG_SIZE
typedef struct MpegAudioParseContext {
    ParseContext pc;
    int frame_size;
    uint32_t header;
    int header_count;
    int no_bitrate;
} MpegAudioParseContext;
#define MPA_HEADER_SIZE 4
#define SAME_HEADER_MASK \

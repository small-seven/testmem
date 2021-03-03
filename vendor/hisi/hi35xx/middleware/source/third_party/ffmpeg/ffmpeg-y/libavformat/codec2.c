#include <memory.h>
#include "libavcodec/codec2utils.h"
#include "libavutil/intreadwrite.h"
#include "avio_internal.h"
#include "avformat.h"
#include "internal.h"
#include "rawdec.h"
#include "rawenc.h"
#include "pcm.h"
#define AVPRIV_CODEC2_HEADER_SIZE 7
#define AVPRIV_CODEC2_MAGIC       0xC0DEC2
#define EXPECTED_CODEC2_MAJOR_VERSION 0
#define EXPECTED_CODEC2_MINOR_VERSION 8
typedef struct {
    const AVClass *class;
    int mode;
    int frames_per_packet;
} Codec2Context;
#define FRAMES_PER_PACKET \
#if CONFIG_CODEC2_DEMUXER
#endif
#if CONFIG_CODEC2_MUXER
#endif
#if CONFIG_CODEC2RAW_DEMUXER
#endif

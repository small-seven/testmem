#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
typedef struct FILMPacket {
    int audio;
    int keyframe;
    int32_t pts;
    int32_t duration;
    int32_t size;
    int32_t index;
    struct FILMPacket *next;
} FILMPacket;
typedef struct FILMOutputContext {
    const AVClass *class;
    int audio_index;
    int video_index;
    int64_t stab_pos;
    FILMPacket *start;
    FILMPacket *last;
    int64_t packet_count;
} FILMOutputContext;
#define READ_BLOCK do {                                                             \

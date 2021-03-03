#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/flac.h"
#include "avformat.h"
#include "avio_internal.h"
#include "flacenc.h"
#include "id3v2.h"
#include "internal.h"
#include "vorbiscomment.h"
#include "libavcodec/bytestream.h"
typedef struct FlacMuxerContext {
    const AVClass *class;
    int write_header;

    int audio_stream_idx;
    int waiting_pics;
    /* audio packets are queued here until we get all the attached pictures */
    AVPacketList *queue, *queue_end;

    /* updated streaminfo sent by the encoder at the end */
    uint8_t *streaminfo;

    unsigned attached_types;
} FlacMuxerContext;

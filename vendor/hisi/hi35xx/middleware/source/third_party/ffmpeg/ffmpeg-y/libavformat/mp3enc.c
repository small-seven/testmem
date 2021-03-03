#include "avformat.h"
#include "avio_internal.h"
#include "id3v1.h"
#include "id3v2.h"
#include "rawenc.h"
#include "libavutil/avstring.h"
#include "libavcodec/mpegaudio.h"
#include "libavcodec/mpegaudiodata.h"
#include "libavcodec/mpegaudiodecheader.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/mathematics.h"
#include "libavutil/replaygain.h"
#define XING_NUM_BAGS 400
#define XING_TOC_SIZE 100
#define XING_SIZE 156
typedef struct MP3Context {
    const AVClass *class;
    ID3v2EncContext id3;
    int id3v2_version;
    int write_id3v1;
    int write_xing;

    /* xing header */
    // a buffer containing the whole XING/LAME frame
    uint8_t *xing_frame;
    int      xing_frame_size;

    AVCRC    audio_crc;     // CRC of the audio data
    uint32_t audio_size;    // total size of the audio data

    // offset of the XING/LAME frame in the file
    int64_t  xing_frame_offset;
    // offset of the XING/INFO tag in the frame
    int xing_offset;

    int32_t frames;
    int32_t size;
    uint32_t want;
    uint32_t seen;
    uint32_t pos;
    uint64_t bag[XING_NUM_BAGS];
    int initial_bitrate;
    int has_variable_bitrate;
    int delay;
    int padding;

    /* index of the audio stream */
    int audio_stream_idx;
    /* number of attached pictures we still need to write */
    int pics_to_write;

    /* audio packets are queued here until we get all the attached pictures */
    AVPacketList *queue, *queue_end;
} MP3Context;
#ifdef FILTER_VBR_HEADERS
#endif

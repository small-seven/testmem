#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "riff.h"
#include "libavutil/avassert.h"
#define XMV_MIN_HEADER_SIZE 36
#define XMV_AUDIO_ADPCM51_FRONTLEFTRIGHT 1
#define XMV_AUDIO_ADPCM51_FRONTCENTERLOW 2
#define XMV_AUDIO_ADPCM51_REARLEFTRIGHT  4
#define XMV_AUDIO_ADPCM51 (XMV_AUDIO_ADPCM51_FRONTLEFTRIGHT | \
#define XMV_BLOCK_ALIGN_SIZE 36
typedef struct XMVVideoPacket {
    int created;
    int stream_index; ///< The decoder stream index for this video packet.

    uint32_t data_size;   ///< The size of the remaining video data.
    uint64_t data_offset; ///< The offset of the video data within the file.

    uint32_t current_frame; ///< The current frame within this video packet.
    uint32_t frame_count;   ///< The amount of frames within this video packet.

    int     has_extradata; ///< Does the video packet contain extra data?
    uint8_t extradata[4];  ///< The extra data

    int64_t last_pts; ///< PTS of the last video frame.
    int64_t pts;      ///< PTS of the most current video frame.
} XMVVideoPacket;
typedef struct XMVAudioPacket {
    int created;
    int stream_index; ///< The decoder stream index for this audio packet.

    /* Stream format properties. */
    uint16_t compression;     ///< The type of compression.
    uint16_t channels;        ///< Number of channels.
    int32_t sample_rate;      ///< Sampling rate.
    uint16_t bits_per_sample; ///< Bits per compressed sample.
    uint64_t bit_rate;        ///< Bits of compressed data per second.
    uint16_t flags;           ///< Flags
    unsigned block_align;     ///< Bytes per compressed block.
    uint16_t block_samples;   ///< Decompressed samples per compressed block.

    enum AVCodecID codec_id; ///< The codec ID of the compression scheme.

    uint32_t data_size;   ///< The size of the remaining audio data.
    uint64_t data_offset; ///< The offset of the audio data within the file.

    uint32_t frame_size; ///< Number of bytes to put into an audio frame.

    uint64_t block_count; ///< Running counter of decompressed audio block.
} XMVAudioPacket;
typedef struct XMVDemuxContext {
    uint16_t audio_track_count; ///< Number of audio track in this file.

    uint32_t this_packet_size; ///< Size of the current packet.
    uint32_t next_packet_size; ///< Size of the next packet.

    uint64_t this_packet_offset; ///< Offset of the current packet.
    uint64_t next_packet_offset; ///< Offset of the next packet.

    uint16_t current_stream; ///< The index of the stream currently handling.
    uint16_t stream_count;   ///< The number of streams in this file.

    uint32_t video_duration;
    uint32_t video_width;
    uint32_t video_height;

    XMVVideoPacket  video; ///< The video packet contained in each packet.
    XMVAudioPacket *audio; ///< The audio packets contained in each packet.
} XMVDemuxContext;

#include <stdint.h>
#include "av1.h"
#include "avc.h"
#include "hevc.h"
#include "avformat.h"
#include "avio_internal.h"
#include "avlanguage.h"
#include "flacenc.h"
#include "internal.h"
#include "isom.h"
#include "matroska.h"
#include "riff.h"
#include "subtitles.h"
#include "vorbiscomment.h"
#include "wv.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/crc.h"
#include "libavutil/dict.h"
#include "libavutil/intfloat.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lfg.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/random_seed.h"
#include "libavutil/rational.h"
#include "libavutil/samplefmt.h"
#include "libavutil/sha.h"
#include "libavutil/stereo3d.h"
#include "libavcodec/xiph.h"
#include "libavcodec/mpeg4audio.h"
#include "libavcodec/internal.h"
typedef struct ebml_master {
    int64_t         pos;                ///< absolute offset in the containing AVIOContext where the master's elements start
    int             sizebytes;          ///< how many bytes were reserved for the size
} ebml_master;
typedef struct mkv_seekhead_entry {
    uint32_t        elementid;
    uint64_t        segmentpos;
} mkv_seekhead_entry;
typedef struct mkv_seekhead {
    int64_t                 filepos;
    int64_t                 segment_offset;     ///< the file offset to the beginning of the segment
    int                     reserved_size;      ///< -1 if appending to file
    int                     max_entries;
    mkv_seekhead_entry      *entries;
    int                     num_entries;
} mkv_seekhead;
typedef struct mkv_cuepoint {
    uint64_t        pts;
    int             stream_idx;
    int             tracknum;
    int64_t         cluster_pos;        ///< file offset of the cluster containing the block
    int64_t         relative_pos;       ///< relative offset from the position of the cluster containing the block
    int64_t         duration;           ///< duration of the block according to time base
} mkv_cuepoint;
typedef struct mkv_cues {
    int64_t         segment_offset;
    mkv_cuepoint    *entries;
    int             num_entries;
} mkv_cues;
typedef struct mkv_track {
    int             write_dts;
    int             has_cue;
    int             sample_rate;
    int64_t         sample_rate_offset;
    int64_t         codecpriv_offset;
    int64_t         ts_offset;
} mkv_track;
typedef struct mkv_attachment {
    int             stream_idx;
    uint32_t        fileuid;
} mkv_attachment;
typedef struct mkv_attachments {
    mkv_attachment  *entries;
    int             num_entries;
} mkv_attachments;
#define MODE_MATROSKAv2 0x01
#define MODE_WEBM       0x02
#define MAX_TRACKS 126
typedef struct MatroskaMuxContext {
    const AVClass   *class;
    int             mode;
    AVIOContext     *tags_bc;
    int64_t         tags_pos;
    AVIOContext     *info_bc;
    int64_t         info_pos;
    AVIOContext     *tracks_bc;
    int64_t         tracks_pos;
    ebml_master     segment;
    int64_t         segment_offset;
    AVIOContext     *cluster_bc;
    int64_t         cluster_pos;        ///< file offset of the current cluster
    int64_t         cluster_pts;
    int64_t         duration_offset;
    int64_t         duration;
    mkv_seekhead    *seekhead;
    mkv_cues        *cues;
    mkv_track       *tracks;
    mkv_attachments *attachments;

    AVPacket        cur_audio_pkt;

    int have_attachments;
    int have_video;

    int reserve_cues_space;
    int cluster_size_limit;
    int64_t cues_pos;
    int64_t cluster_time_limit;
    int is_dash;
    int dash_track_number;
    int is_live;
    int write_crc;

    uint32_t chapter_id_offset;
    int wrote_chapters;

    int64_t last_track_timestamp[MAX_TRACKS];

    int64_t *stream_durations;
    int64_t *stream_duration_offsets;

    int allow_raw_vfw;
} MatroskaMuxContext;
#define MAX_EBML_HEADER_SIZE 35
#define MAX_SEEKENTRY_SIZE 21
#define MAX_CUETRACKPOS_SIZE 35
#define MAX_CUEPOINT_CONTENT_SIZE(num_tracks) 10 + MAX_CUETRACKPOS_SIZE * num_tracks
#define OPUS_SEEK_PREROLL 80000000
#if FF_API_CONVERGENCE_DURATION
#endif
#define OFFSET(x) offsetof(MatroskaMuxContext, x)
#define FLAGS AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_MATROSKA_MUXER
#endif
#if CONFIG_WEBM_MUXER
#endif
#if CONFIG_MATROSKA_AUDIO_MUXER
#endif

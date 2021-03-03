#include "config.h"
#include <float.h>
#include <stdint.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if CONFIG_GCRYPT
#include <gcrypt.h>
#elif CONFIG_OPENSSL
#include <openssl/rand.h>
#endif
#include "libavutil/avassert.h"
#include "libavutil/mathematics.h"
#include "libavutil/parseutils.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/random_seed.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "avio_internal.h"
#if CONFIG_HTTP_PROTOCOL
#include "http.h"
#endif
#include "hlsplaylist.h"
#include "internal.h"
#include "os_support.h"
typedef enum {
  HLS_START_SEQUENCE_AS_START_NUMBER = 0,
  HLS_START_SEQUENCE_AS_SECONDS_SINCE_EPOCH = 1,
  HLS_START_SEQUENCE_AS_FORMATTED_DATETIME = 2,  // YYYYMMDDhhmmss
} StartSequenceSourceType;
typedef enum {
    CODEC_ATTRIBUTE_WRITTEN = 0,
    CODEC_ATTRIBUTE_WILL_NOT_BE_WRITTEN,
} CodecAttributeStatus;
#define KEYSIZE 16
#define LINE_BUFFER_SIZE MAX_URL_SIZE
#define HLS_MICROSECOND_UNIT   1000000
#define POSTFIX_PATTERN "_%d"
typedef struct HLSSegment {
    char filename[MAX_URL_SIZE];
    char sub_filename[MAX_URL_SIZE];
    double duration; /* in seconds */
    int discont;
    int64_t pos;
    int64_t size;
    int64_t keyframe_pos;
    int64_t keyframe_size;
    unsigned var_stream_idx;

    char key_uri[LINE_BUFFER_SIZE + 1];
    char iv_string[KEYSIZE*2 + 1];

    struct HLSSegment *next;
} HLSSegment;
typedef enum HLSFlags {
    // Generate a single media file and use byte ranges in the playlist.
    HLS_SINGLE_FILE = (1 << 0),
    HLS_DELETE_SEGMENTS = (1 << 1),
    HLS_ROUND_DURATIONS = (1 << 2),
    HLS_DISCONT_START = (1 << 3),
    HLS_OMIT_ENDLIST = (1 << 4),
    HLS_SPLIT_BY_TIME = (1 << 5),
    HLS_APPEND_LIST = (1 << 6),
    HLS_PROGRAM_DATE_TIME = (1 << 7),
    HLS_SECOND_LEVEL_SEGMENT_INDEX = (1 << 8), // include segment index in segment filenames when use_localtime  e.g.: %%03d
    HLS_SECOND_LEVEL_SEGMENT_DURATION = (1 << 9), // include segment duration (microsec) in segment filenames when use_localtime  e.g.: %%09t
    HLS_SECOND_LEVEL_SEGMENT_SIZE = (1 << 10), // include segment size (bytes) in segment filenames when use_localtime  e.g.: %%014s
    HLS_TEMP_FILE = (1 << 11),
    HLS_PERIODIC_REKEY = (1 << 12),
    HLS_INDEPENDENT_SEGMENTS = (1 << 13),
    HLS_I_FRAMES_ONLY = (1 << 14),
} HLSFlags;
typedef enum {
    SEGMENT_TYPE_MPEGTS,
    SEGMENT_TYPE_FMP4,
} SegmentType;
typedef struct VariantStream {
    unsigned var_stream_idx;
    unsigned number;
    int64_t sequence;
    ff_const59 AVOutputFormat *oformat;
    ff_const59 AVOutputFormat *vtt_oformat;
    AVIOContext *out;
    int packets_written;
    int init_range_length;

    AVFormatContext *avf;
    AVFormatContext *vtt_avf;

    int has_video;
    int has_subtitle;
    int new_start;
    double dpp;           // duration per packet
    int64_t start_pts;
    int64_t end_pts;
    int64_t video_lastpos;
    int64_t video_keyframe_pos;
    int64_t video_keyframe_size;
    double duration;      // last segment duration computed so far, in seconds
    int64_t start_pos;    // last segment starting position
    int64_t size;         // last segment size
    int nb_entries;
    int discontinuity_set;
    int discontinuity;
    int reference_stream_index;

    HLSSegment *segments;
    HLSSegment *last_segment;
    HLSSegment *old_segments;

    char *basename;
    char *vtt_basename;
    char *vtt_m3u8_name;
    char *m3u8_name;

    double initial_prog_date_time;
    char current_segment_final_filename_fmt[MAX_URL_SIZE]; // when renaming segments

    char *fmp4_init_filename;
    char *base_output_dirname;

    AVStream **streams;
    char codec_attr[128];
    CodecAttributeStatus attr_status;
    unsigned int nb_streams;
    int m3u8_created; /* status of media play-list creation */
    int is_default; /* default status of audio group */
    char *language; /* audio lauguage name */
    char *agroup; /* audio group name */
    char *ccgroup; /* closed caption group name */
    char *baseurl;
    char *varname; // variant name
} VariantStream;
typedef struct ClosedCaptionsStream {
    char *ccgroup; /* closed caption group name */
    char *instreamid; /* closed captions INSTREAM-ID */
    char *language; /* closed captions langauge */
} ClosedCaptionsStream;
typedef struct HLSContext {
    const AVClass *class;  // Class for private options.
    int64_t start_sequence;
    uint32_t start_sequence_source_type;  // enum StartSequenceSourceType

    float time;            // Set by a private option.
    float init_time;       // Set by a private option.
    int max_nb_segments;   // Set by a private option.
    int hls_delete_threshold; // Set by a private option.
#if FF_API_HLS_WRAP
    int  wrap;             // Set by a private option.
#endif
    uint32_t flags;        // enum HLSFlags
    uint32_t pl_type;      // enum PlaylistType
    char *segment_filename;
    char *fmp4_init_filename;
    int segment_type;

    int use_localtime;      ///< flag to expand filename with localtime
    int use_localtime_mkdir;///< flag to mkdir dirname in timebased filename
    int allowcache;
    int64_t recording_time;
    int64_t max_seg_size; // every segment file max size

    char *baseurl;
    char *format_options_str;
    char *vtt_format_options_str;
    char *subtitle_filename;
    AVDictionary *format_options;

    int encrypt;
    char *key;
    char *key_url;
    char *iv;
    char *key_basename;
    int encrypt_started;

    char *key_info_file;
    char key_file[LINE_BUFFER_SIZE + 1];
    char key_uri[LINE_BUFFER_SIZE + 1];
    char key_string[KEYSIZE*2 + 1];
    char iv_string[KEYSIZE*2 + 1];
    AVDictionary *vtt_format_options;

    char *method;
    char *user_agent;

    VariantStream *var_streams;
    unsigned int nb_varstreams;
    ClosedCaptionsStream *cc_streams;
    unsigned int nb_ccstreams;

    int master_m3u8_created; /* status of master play-list creation */
    char *master_m3u8_url; /* URL of the master m3u8 file */
    int version; /* HLS version */
    char *var_stream_map; /* user specified variant stream map string */
    char *cc_stream_map; /* user specified closed caption streams map string */
    char *master_pl_name;
    unsigned int master_publish_rate;
    int http_persistent;
    AVIOContext *m3u8_out;
    AVIOContext *sub_m3u8_out;
    int64_t timeout;
    int ignore_io_errors;
    char *headers;
    int has_default_key; /* has DEFAULT field of var_stream_map */
    int has_video_m3u8; /* has video stream m3u8 list */
} HLSContext;
#if CONFIG_HTTP_PROTOCOL
#endif
#if CONFIG_HTTP_PROTOCOL
#endif
#if CONFIG_GCRYPT
#elif CONFIG_OPENSSL
#else
#endif
#if FF_API_HLS_WRAP
#else
#endif
#if FF_API_HLS_WRAP
#else
#endif
#if FF_API_HLS_WRAP
#else
#endif
#if FF_API_HLS_WRAP
#else
#endif
#if FF_API_HLS_WRAP
#else
#endif
#define OFFSET(x) offsetof(HLSContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_HLS_WRAP
#endif
#if FF_API_HLS_USE_LOCALTIME
#endif
#if FF_API_HLS_USE_LOCALTIME
#endif

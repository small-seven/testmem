#include <float.h>
#include <time.h>
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/parseutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/time.h"
#include "libavutil/timecode.h"
#include "libavutil/time_internal.h"
#include "libavutil/timestamp.h"
typedef struct SegmentListEntry {
    int index;
    double start_time, end_time;
    int64_t start_pts;
    int64_t offset_pts;
    char *filename;
    struct SegmentListEntry *next;
    int64_t last_duration;
} SegmentListEntry;
typedef enum {
    LIST_TYPE_UNDEFINED = -1,
    LIST_TYPE_FLAT = 0,
    LIST_TYPE_CSV,
    LIST_TYPE_M3U8,
    LIST_TYPE_EXT, ///< deprecated
    LIST_TYPE_FFCONCAT,
    LIST_TYPE_NB,
} ListType;
#define SEGMENT_LIST_FLAG_CACHE 1
#define SEGMENT_LIST_FLAG_LIVE  2
typedef struct SegmentContext {
    const AVClass *class;  /**< Class for private options. */
    int segment_idx;       ///< index of the segment file to write, starting from 0
    int segment_idx_wrap;  ///< number after which the index wraps
    int segment_idx_wrap_nb;  ///< number of time the index has wraped
    int segment_count;     ///< number of segment files already written
    ff_const59 AVOutputFormat *oformat;
    AVFormatContext *avf;
    char *format;              ///< format to use for output segment files
    char *format_options_str;  ///< format options to use for output segment files
    AVDictionary *format_options;
    char *list;            ///< filename for the segment list file
    int   list_flags;      ///< flags affecting list generation
    int   list_size;       ///< number of entries for the segment list file

    int use_clocktime;    ///< flag to cut segments at regular clock time
    int64_t clocktime_offset; //< clock offset for cutting the segments at regular clock time
    int64_t clocktime_wrap_duration; //< wrapping duration considered for starting a new segment
    int64_t last_val;      ///< remember last time for wrap around detection
    int cut_pending;
    int header_written;    ///< whether we've already called avformat_write_header

    char *entry_prefix;    ///< prefix to add to list entry filenames
    int list_type;         ///< set the list type
    AVIOContext *list_pb;  ///< list file put-byte context
    char *time_str;        ///< segment duration specification string
    int64_t time;          ///< segment duration
    int use_strftime;      ///< flag to expand filename with strftime
    int increment_tc;      ///< flag to increment timecode if found

    char *times_str;       ///< segment times specification string
    int64_t *times;        ///< list of segment interval specification
    int nb_times;          ///< number of elments in the times array

    char *frames_str;      ///< segment frame numbers specification string
    int *frames;           ///< list of frame number specification
    int nb_frames;         ///< number of elments in the frames array
    int frame_count;       ///< total number of reference frames
    int segment_frame_count; ///< number of reference frames in the segment

    int64_t time_delta;
    int  individual_header_trailer; /**< Set by a private option. */
    int  write_header_trailer; /**< Set by a private option. */
    char *header_filename;  ///< filename to write the output header to

    int reset_timestamps;  ///< reset timestamps at the beginning of each segment
    int64_t initial_offset;    ///< initial timestamps offset, expressed in microseconds
    char *reference_stream_specifier; ///< reference stream specifier
    int   reference_stream_index;
    int   break_non_keyframes;
    int   write_empty;

    int use_rename;
    char temp_list_filename[1024];

    SegmentListEntry cur_entry;
    SegmentListEntry *segment_list_entries;
    SegmentListEntry *segment_list_entries_end;
} SegmentContext;
#if FF_API_LAVF_AVCTX
#endif
#define FAIL(err) ret = err; goto end
#define FAIL(err) ret = err; goto end
static void seg_free(AVFormatContext *s)
{
    SegmentContext *seg = s->priv_data;
    ff_format_io_close(seg->avf, &seg->list_pb);
    avformat_free_context(seg->avf);
    seg->avf = NULL;
}
#define OFFSET(x) offsetof(SegmentContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_SEGMENT_MUXER
#endif
#if CONFIG_STREAM_SEGMENT_MUXER
#endif

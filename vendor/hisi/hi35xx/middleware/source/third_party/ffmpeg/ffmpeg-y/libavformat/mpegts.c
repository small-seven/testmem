#include "libavutil/buffer.h"
#include "libavutil/crc.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/get_bits.h"
#include "libavcodec/opus.h"
#include "avformat.h"
#include "mpegts.h"
#include "internal.h"
#include "avio_internal.h"
#include "mpeg.h"
#include "isom.h"
#if CONFIG_ICONV
#include <iconv.h>
#endif
#define MAX_RESYNC_SIZE 65536
#define MAX_PES_PAYLOAD 200 * 1024
#define MAX_MP4_DESCR_COUNT 16
#define MOD_UNLIKELY(modulus, dividend, divisor, prev_dividend)                \
#define PROBE_PACKET_MAX_BUF 8192
#define PROBE_PACKET_MARGIN 5
typedef struct MpegTSFilter MpegTSFilter;

typedef int PESCallback (MpegTSFilter *f, const uint8_t *buf, int len,
                         int is_start, int64_t pos);

typedef struct MpegTSPESFilter {
    PESCallback *pes_cb;
    void *opaque;
} MpegTSPESFilter;
typedef void SectionCallback (MpegTSFilter *f, const uint8_t *buf, int len);

typedef void SetServiceCallback (void *opaque, int ret);

typedef struct MpegTSSectionFilter {
    int section_index;
    int section_h_size;
    int last_ver;
    unsigned crc;
    unsigned last_crc;
    uint8_t *section_buf;
    unsigned int check_crc : 1;
    unsigned int end_of_section_reached : 1;
    SectionCallback *section_cb;
    void *opaque;
} MpegTSSectionFilter;
#define MAX_PIDS_PER_PROGRAM 64
#define SIZE_STAT_THRESHOLD 10
#define MPEGTS_OPTIONS \
#define PES_START_SIZE  6
#define PES_HEADER_SIZE 9
#define MAX_PES_HEADER_SIZE (9 + 255)
typedef struct PESContext {
    int pid;
    int pcr_pid; /**< if -1 then all packets containing PCR are considered */
    int stream_type;
    MpegTSContext *ts;
    AVFormatContext *stream;
    AVStream *st;
    AVStream *sub_st; /**< stream for the embedded AC3 stream in HDMV TrueHD */
    enum MpegTSState state;
    /* used to get the format */
    int data_index;
    int flags; /**< copied to the AVPacket flags */
    int total_size;
    int pes_header_size;
    int extended_stream_id;
    uint8_t stream_id;
    int64_t pts, dts;
    int64_t ts_packet_pos; /**< position of first TS packet of this PES packet */
    uint8_t header[MAX_PES_HEADER_SIZE];
    AVBufferRef *buffer;
    SLConfigDescr sl;
    int merged_st;
} PESContext;
typedef struct SectionHeader {
    uint8_t tid;
    uint16_t id;
    uint8_t version;
    uint8_t sec_num;
    uint8_t last_sec_num;
} SectionHeader;
#if CONFIG_ICONV
#endif
typedef struct StreamType {
    uint32_t stream_type;
    enum AVMediaType codec_type;
    enum AVCodecID codec_id;
} StreamType;
#if !CONFIG_LOAS_DEMUXER
#endif
#define MAX_LEVEL 4
typedef struct MP4DescrParseContext {
    AVFormatContext *s;
    AVIOContext pb;
    Mp4Descr *descr;
    Mp4Descr *active_descr;
    int descr_count;
    int max_descr_count;
    int level;
    int predefined_SLConfigDescriptor_seen;
} MP4DescrParseContext;
#define R8_CHECK_CLIP_MAX(dst, maxv) do {                       \
#define CHECK_COUNT 10
#define CHECK_BLOCK 100
#define MAX_PACKET_READAHEAD ((128 * 1024) / 188)
static void mpegts_free(MpegTSContext *ts)
{
    int i;

    clear_programs(ts);

    for (i = 0; i < NB_PID_MAX; i++)
        if (ts->pids[i])
            mpegts_close_filter(ts, ts->pids[i]);
}

#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "mpeg.h"
#define SERIES1_PES_LENGTH  11    /* length of audio PES hdr on S1 */
#define SERIES2_PES_LENGTH  16    /* length of audio PES hdr on S2 */
#define AC3_PES_LENGTH      14    /* length of audio PES hdr for AC3 */
#define VIDEO_PES_LENGTH    16    /* length of video PES header */
#define DTIVO_PTS_OFFSET    6     /* offs into PES for MPEG PTS on DTivo */
#define SA_PTS_OFFSET       9     /* offset into PES for MPEG PTS on SA */
#define AC3_PTS_OFFSET      9     /* offset into PES for AC3 PTS on DTivo */
#define VIDEO_PTS_OFFSET    9     /* offset into PES for video PTS on all */
#define AC3_PKT_LENGTH      1536  /* size of TiVo AC3 pkts (w/o PES hdr) */
#define TIVO_PES_FILEID   0xf5467abd
#define CHUNK_SIZE        (128 * 1024)
#define CHUNK_PEEK_COUNT  3      /* number of chunks to probe */
typedef struct TyRecHdr {
    int64_t   rec_size;
    uint8_t   ex[2];
    uint8_t   rec_type;
    uint8_t   subrec_type;
    uint64_t  ty_pts;            /* TY PTS in the record header */
} TyRecHdr;
typedef enum {
    TIVO_TYPE_UNKNOWN,
    TIVO_TYPE_SA,
    TIVO_TYPE_DTIVO
} TiVo_type;
typedef enum {
    TIVO_SERIES_UNKNOWN,
    TIVO_SERIES1,
    TIVO_SERIES2
} TiVo_series;
typedef enum {
    TIVO_AUDIO_UNKNOWN,
    TIVO_AUDIO_AC3,
    TIVO_AUDIO_MPEG
} TiVo_audio;
typedef struct TySeqTable {
    uint64_t    timestamp;
    uint8_t     chunk_bitmask[8];
} TySeqTable;
typedef struct TYDemuxContext {
    unsigned        cur_chunk;
    unsigned        cur_chunk_pos;
    int64_t         cur_pos;
    TiVo_type       tivo_type;        /* TiVo type (SA / DTiVo) */
    TiVo_series     tivo_series;      /* Series1 or Series2 */
    TiVo_audio      audio_type;       /* AC3 or MPEG */
    int             pes_length;       /* Length of Audio PES header */
    int             pts_offset;       /* offset into audio PES of PTS */
    uint8_t         pes_buffer[20];   /* holds incomplete pes headers */
    int             pes_buf_cnt;      /* how many bytes in our buffer */
    size_t          ac3_pkt_size;     /* length of ac3 pkt we've seen so far */
    uint64_t        last_ty_pts;      /* last TY timestamp we've seen */
    unsigned        seq_table_size;   /* number of entries in SEQ table */

    int64_t         first_audio_pts;
    int64_t         last_audio_pts;
    int64_t         last_video_pts;

    TyRecHdr       *rec_hdrs;         /* record headers array */
    int             cur_rec;          /* current record in this chunk */
    int             num_recs;         /* number of recs in this chunk */
    int             seq_rec;          /* record number where seq start is */
    TySeqTable     *seq_table;        /* table of SEQ entries from mstr chk */
    int             first_chunk;

    uint8_t         chunk[CHUNK_SIZE];
} TYDemuxContext;

#include "libavutil/attributes.h"
#include "libavutil/mathematics.h"
#include "avformat.h"
#include "internal.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#define NSV_MAX_RESYNC (500*1024)
#define NSV_MAX_RESYNC_TRIES 300
#if 0
#endif
/*typedef struct CodecTag {
    int id;
    unsigned int tag;
} CodecTag;*/
#define T_NSVF MKTAG('N', 'S', 'V', 'f') /* file header */
#define T_NSVS MKTAG('N', 'S', 'V', 's') /* chunk header */
#define T_TOC2 MKTAG('T', 'O', 'C', '2') /* extra index marker */
#define T_NONE MKTAG('N', 'O', 'N', 'E') /* null a/v 4CC */
#define T_SUBT MKTAG('S', 'U', 'B', 'T') /* subtitle aux data */
#define T_ASYN MKTAG('A', 'S', 'Y', 'N') /* async a/v aux marker */
#define T_KEYF MKTAG('K', 'E', 'Y', 'F') /* video keyframe aux marker (addition) */
#define TB_NSVF MKBETAG('N', 'S', 'V', 'f')
#define TB_NSVS MKBETAG('N', 'S', 'V', 's')
#define NSV_ST_VIDEO 0
#define NSV_ST_AUDIO 1
#define NSV_ST_SUBT 2
typedef struct NSVStream {
    int frame_offset; /* current frame (video) or byte (audio) counter
                         (used to compute the pts) */
    int scale;
    int rate;
    int sample_size; /* audio only data */
    int start;

    int new_frame_offset; /* temporary storage (used during seek) */
    int cum_len; /* temporary storage (used during seek) */
} NSVStream;
typedef struct NSVContext {
    int  base_offset;
    int  NSVf_end;
    uint32_t *nsvs_file_offset;
    int index_entries;
    enum NSVStatus state;
    AVPacket ahead[2]; /* [v, a] if .data is !NULL there is something */
    /* cached */
    int64_t duration;
    uint32_t vtag, atag;
    uint16_t vwidth, vheight;
    int16_t avsync;
    AVRational framerate;
    uint32_t *nsvs_timestamps;
    int nsvf;
} NSVContext;

#include <math.h>
#include "avformat.h"
#include "internal.h"
#include "avi.h"
#include "avio_internal.h"
#include "riff.h"
#include "mpegts.h"
#include "libavformat/avlanguage.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/avassert.h"
#include "libavutil/timestamp.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/raw.h"
typedef struct AVIIentry {
    char tag[4];
    unsigned int flags;
    unsigned int pos;
    unsigned int len;
} AVIIentry;
#define AVI_INDEX_CLUSTER_SIZE 16384
#define AVI_MASTER_INDEX_PREFIX_SIZE    (8+2+1+1+4+8+4+4)
#define AVI_MASTER_INDEX_ENTRY_SIZE     16  /* bytes per entry */
#define AVI_MASTER_INDEX_SIZE_DEFAULT   256 /* number of entries */
typedef struct AVIIndex {
    int64_t     indx_start;
    int64_t     audio_strm_offset;
    int         entry;
    int         ents_allocated;
    int         master_odml_riff_id_base;
    AVIIentry** cluster;
} AVIIndex;
typedef struct AVIContext {
    const AVClass *class;
    int64_t riff_start, movi_list, odml_list;
    int64_t frames_hdr_all;
    int riff_id;
    int reserve_index_space;
    int master_index_max_size;
    int write_channel_mask;
} AVIContext;
typedef struct AVIStream {
    int64_t frames_hdr_strm;
    int64_t audio_strm_length;
    int packet_count;
    int entry;
    int max_size;
    int sample_requested;

    int64_t last_dts;

    AVIIndex indexes;

    int64_t strh_flags_offset;

    uint32_t palette[AVPALETTE_COUNT];
    uint32_t old_palette[AVPALETTE_COUNT];
    int64_t pal_offset;
} AVIStream;
#define OFFSET(x) offsetof(AVIContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM

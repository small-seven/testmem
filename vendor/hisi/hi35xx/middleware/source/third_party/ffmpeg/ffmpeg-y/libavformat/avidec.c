#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bswap.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "avformat.h"
#include "avi.h"
#include "dv.h"
#include "internal.h"
#include "isom.h"
#include "riff.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/exif.h"
#include "libavcodec/internal.h"
typedef struct AVIStream {
    int64_t frame_offset;   /* current frame (video) or byte (audio) counter
                             * (used to compute the pts) */
    int remaining;
    int packet_size;

    uint32_t handler;
    uint32_t scale;
    uint32_t rate;
    int sample_size;        /* size of one sample (or packet)
                             * (in the rate/scale sense) in bytes */

    int64_t cum_len;        /* temporary storage (used during seek) */
    int prefix;             /* normally 'd'<<8 + 'c' or 'w'<<8 + 'b' */
    int prefix_count;
    uint32_t pal[256];
    int has_pal;
    int dshow_block_align;  /* block align variable used to emulate bugs in
                             * the MS dshow demuxer */

    AVFormatContext *sub_ctx;
    AVPacket sub_pkt;
    uint8_t *sub_buffer;

    int64_t seek_pos;
} AVIStream;
typedef struct AVIContext {
    const AVClass *class;
    int64_t riff_end;
    int64_t movi_end;
    int64_t fsize;
    int64_t io_fsize;
    int64_t movi_list;
    int64_t last_pkt_pos;
    int index_loaded;
    int is_odml;
    int non_interleaved;
    int stream_index;
    DVDemuxContext *dv_demux;
    int odml_depth;
    int use_odml;
#define MAX_ODML_DEPTH 1000
    int64_t dts_max;
} AVIContext;
#define print_tag(str, tag, size)                                      \
#if FF_API_LAVF_AVCTX
#endif

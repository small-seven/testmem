#include <inttypes.h>
#include "libavutil/bswap.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define SMACKER_PAL 0x01
#define SMACKER_FLAG_RING_FRAME 0x01
typedef struct SmackerContext {
    /* Smacker file header */
    uint32_t magic;
    uint32_t width, height;
    uint32_t frames;
    int      pts_inc;
    uint32_t flags;
    uint32_t audio[7];
    uint32_t treesize;
    uint32_t mmap_size, mclr_size, full_size, type_size;
    uint8_t  aflags[7];
    uint32_t rates[7];
    uint32_t pad;
    /* frame info */
    uint32_t *frm_size;
    uint8_t  *frm_flags;
    /* internal variables */
    int cur_frame;
    int is_ver4;
    int64_t cur_pts;
    /* current frame for demuxing */
    uint8_t pal[768];
    int indexes[7];
    int videoindex;
    uint8_t *bufs[7];
    int buf_sizes[7];
    int stream_id[7];
    int curstream;
    int64_t nextpos;
    int64_t aud_pts[7];
} SmackerContext;
typedef struct SmackerFrame {
    int64_t pts;
    int stream;
} SmackerFrame;

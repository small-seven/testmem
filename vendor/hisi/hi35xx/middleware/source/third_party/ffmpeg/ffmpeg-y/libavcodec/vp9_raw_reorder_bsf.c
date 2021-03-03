#include "libavutil/avassert.h"
#include "libavutil/intmath.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "get_bits.h"
#include "put_bits.h"
#define FRAME_SLOTS 8
typedef struct VP9RawReorderFrame {
    AVPacket    *packet;
    int          needs_output;
    int          needs_display;

    int64_t      pts;
    int64_t      sequence;
    unsigned int slots;

    unsigned int profile;

    unsigned int show_existing_frame;
    unsigned int frame_to_show;

    unsigned int frame_type;
    unsigned int show_frame;
    unsigned int refresh_frame_flags;
} VP9RawReorderFrame;
typedef struct VP9RawReorderContext {
    int64_t sequence;
    VP9RawReorderFrame *slot[FRAME_SLOTS];
    VP9RawReorderFrame *next_frame;
} VP9RawReorderContext;
static void vp9_raw_reorder_frame_free(VP9RawReorderFrame **frame)
{
    if (*frame)
        av_packet_free(&(*frame)->packet);
    av_freep(frame);
}

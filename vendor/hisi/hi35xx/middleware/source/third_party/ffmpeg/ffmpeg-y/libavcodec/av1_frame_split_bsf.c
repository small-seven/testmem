#include "libavutil/avassert.h"
#include "avcodec.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_av1.h"
typedef struct AV1FSplitContext {
    AVPacket *buffer_pkt;
    CodedBitstreamContext *cbc;
    CodedBitstreamFragment temporal_unit;

    int nb_frames;
    int cur_frame;
    int cur_frame_idx;
    int last_frame_idx;
} AV1FSplitContext;

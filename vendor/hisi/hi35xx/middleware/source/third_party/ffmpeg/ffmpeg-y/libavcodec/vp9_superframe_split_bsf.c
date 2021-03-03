#include <stddef.h>
#include "avcodec.h"
#include "bsf.h"
#include "bytestream.h"
#include "get_bits.h"
typedef struct VP9SFSplitContext {
    AVPacket *buffer_pkt;

    int nb_frames;
    int next_frame;
    size_t next_frame_offset;
    int sizes[8];
} VP9SFSplitContext;

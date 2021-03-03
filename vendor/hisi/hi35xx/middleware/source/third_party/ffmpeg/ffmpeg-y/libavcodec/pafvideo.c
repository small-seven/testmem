#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "copy_block.h"
#include "internal.h"
typedef struct PAFVideoDecContext {
    AVFrame  *pic;
    GetByteContext gb;

    int width;
    int height;

    int current_frame;
    uint8_t *frame[4];
    int frame_size;
    int video_size;

    uint8_t *opcodes;
} PAFVideoDecContext;

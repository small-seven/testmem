#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
#define ROQ_FRAME_SIZE           735
#define ROQ_HEADER_SIZE   8
#define MAX_DPCM (127*127)
typedef struct ROQDPCMContext {
    short lastSample[2];
    int input_frames;
    int buffered_samples;
    int16_t *frame_buffer;
    int64_t first_pts;
} ROQDPCMContext;

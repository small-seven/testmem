#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define MAX_RLE_BULK   127
#define MAX_RLE_REPEAT 128
#define MAX_RLE_SKIP   254
typedef struct QtrleEncContext {
    AVCodecContext *avctx;
    int pixel_size;
    AVFrame *previous_frame;
    unsigned int max_buf_size;
    int logical_width;
    /**
     * This array will contain at ith position the value of the best RLE code
     * if the line started at pixel i
     * There can be 3 values :
     * skip (0)     : skip as much as possible pixels because they are equal to the
     *                previous frame ones
     * repeat (<-1) : repeat that pixel -rle_code times, still as much as
     *                possible
     * copy (>0)    : copy the raw next rle_code pixels */
    signed char *rlecode_table;
    /**
     * This array will contain the length of the best rle encoding of the line
     * starting at ith pixel */
    int *length_table;
    /**
     * Will contain at ith position the number of consecutive pixels equal to the previous
     * frame starting from pixel i */
    uint8_t* skip_table;

    /** Encoded frame is a key frame */
    int key_frame;
} QtrleEncContext;
#if FF_API_CODED_FRAME
#endif

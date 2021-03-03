#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "golomb.h"
typedef struct FICThreadContext {
    DECLARE_ALIGNED(16, int16_t, block)[64];
    uint8_t *src;
    int slice_h;
    int src_size;
    int y_off;
    int p_frame;
} FICThreadContext;
typedef struct FICContext {
    AVClass *class;
    AVCodecContext *avctx;
    AVFrame *frame;
    AVFrame *final_frame;

    FICThreadContext *slice_data;
    int slice_data_size;

    const uint8_t *qmat;

    enum AVPictureType cur_frame_type;

    int aligned_width, aligned_height;
    int num_slices, slice_h;

    uint8_t cursor_buf[4096];
    int skip_cursor;
} FICContext;
#define FIC_HEADER_SIZE 27
#define CURSOR_OFFSET 59

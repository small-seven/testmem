#include <inttypes.h>
#include "libavutil/attributes.h"
#include "internal.h"
#include "avcodec.h"
#include "mpegutils.h"
#include "h264dec.h"
#include "h264data.h"
#include "golomb.h"
#include "hpeldsp.h"
#include "mathops.h"
#include "rectangle.h"
#include "tpeldsp.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "svq1.h"
typedef struct SVQ3Frame {
    AVFrame *f;

    AVBufferRef *motion_val_buf[2];
    int16_t (*motion_val[2])[2];

    AVBufferRef *mb_type_buf;
    uint32_t *mb_type;


    AVBufferRef *ref_index_buf[2];
    int8_t *ref_index[2];
} SVQ3Frame;
typedef struct SVQ3Context {
    AVCodecContext *avctx;

    H264DSPContext  h264dsp;
    H264PredContext hpc;
    HpelDSPContext hdsp;
    TpelDSPContext tdsp;
    VideoDSPContext vdsp;

    SVQ3Frame *cur_pic;
    SVQ3Frame *next_pic;
    SVQ3Frame *last_pic;
    GetBitContext gb;
    GetBitContext gb_slice;
    uint8_t *slice_buf;
    int slice_size;
    int halfpel_flag;
    int thirdpel_flag;
    int has_watermark;
    uint32_t watermark_key;
    uint8_t *buf;
    int buf_size;
    int adaptive_quant;
    int next_p_frame_damaged;
    int h_edge_pos;
    int v_edge_pos;
    int last_frame_output;
    int slice_num;
    int qscale;
    int cbp;
    int frame_num;
    int frame_num_offset;
    int prev_frame_num_offset;
    int prev_frame_num;

    enum AVPictureType pict_type;
    enum AVPictureType slice_type;
    int low_delay;

    int mb_x, mb_y;
    int mb_xy;
    int mb_width, mb_height;
    int mb_stride, mb_num;
    int b_stride;

    uint32_t *mb2br_xy;

    int chroma_pred_mode;
    int intra16x16_pred_mode;

    int8_t   intra4x4_pred_mode_cache[5 * 8];
    int8_t (*intra4x4_pred_mode);

    unsigned int top_samples_available;
    unsigned int topright_samples_available;
    unsigned int left_samples_available;

    uint8_t *edge_emu_buffer;

    DECLARE_ALIGNED(16, int16_t, mv_cache)[2][5 * 8][2];
    DECLARE_ALIGNED(8,  int8_t, ref_cache)[2][5 * 8];
    DECLARE_ALIGNED(16, int16_t, mb)[16 * 48 * 2];
    DECLARE_ALIGNED(16, int16_t, mb_luma_dc)[3][16 * 2];
    DECLARE_ALIGNED(8, uint8_t, non_zero_count_cache)[15 * 8];
    uint32_t dequant4_coeff[QP_MAX_NUM + 1][16];
    int block_offset[2 * (16 * 3)];
} SVQ3Context;
#define FULLPEL_MODE  1
#define HALFPEL_MODE  2
#define THIRDPEL_MODE 3
#define PREDICT_MODE  4
#define stride 16
#undef stride
#if CONFIG_ZLIB
#else
#endif

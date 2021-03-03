#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/lfg.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "elbg.h"
#include "internal.h"
#define CVID_HEADER_SIZE 10
#define STRIP_HEADER_SIZE 12
#define CHUNK_HEADER_SIZE 4
#define MB_SIZE 4           //4x4 MBs
#define MB_AREA (MB_SIZE * MB_SIZE)
#define VECTOR_MAX     6    // six or four entries per vector depending on format
#define CODEBOOK_MAX 256    // size of a codebook
#define MAX_STRIPS  32      // Note: having fewer choices regarding the number of strips speeds up encoding (obviously)
#define MIN_STRIPS   1      // Note: having more strips speeds up encoding the frame (this is less obvious)
typedef enum CinepakMode {
    MODE_V1_ONLY = 0,
    MODE_V1_V4,
    MODE_MC,

    MODE_COUNT,
} CinepakMode;
typedef enum mb_encoding {
    ENC_V1,
    ENC_V4,
    ENC_SKIP,

    ENC_UNCERTAIN
} mb_encoding;
typedef struct mb_info {
    int v1_vector;              // index into v1 codebook
    int v1_error;               // error when using V1 encoding
    int v4_vector[4];           // indices into v4 codebook
    int v4_error;               // error when using V4 encoding
    int skip_error;             // error when block is skipped (aka copied from last frame)
    mb_encoding best_encoding;  // last result from calculate_mode_score()
} mb_info;
typedef struct strip_info {
    int v1_codebook[CODEBOOK_MAX * VECTOR_MAX];
    int v4_codebook[CODEBOOK_MAX * VECTOR_MAX];
    int v1_size;
    int v4_size;
    CinepakMode mode;
} strip_info;
typedef struct CinepakEncContext {
    const AVClass *class;
    AVCodecContext *avctx;
    unsigned char *pict_bufs[4], *strip_buf, *frame_buf;
    AVFrame *last_frame;
    AVFrame *best_frame;
    AVFrame *scratch_frame;
    AVFrame *input_frame;
    enum AVPixelFormat pix_fmt;
    int w, h;
    int frame_buf_size;
    int curframe, keyint;
    AVLFG randctx;
    uint64_t lambda;
    int *codebook_input;
    int *codebook_closest;
    mb_info *mb;                // MB RD state
    int min_strips;             // the current limit
    int max_strips;             // the current limit
    // options
    int max_extra_cb_iterations;
    int skip_empty_cb;
    int min_min_strips;
    int max_max_strips;
    int strip_number_delta_range;
} CinepakEncContext;
#define OFFSET(x) offsetof(CinepakEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define CERTAIN(x) ((x) != ENC_UNCERTAIN)
#define SMALLEST_CODEBOOK 1

#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include "avfilter.h"
#define MAX_LEVEL 8 /* quality levels */
#define BLOCK 16
typedef struct USPPContext {
    const AVClass *av_class;
    int log2_count;
    int hsub, vsub;
    int qp;
    int qscale_type;
    int temp_stride[3];
    uint8_t *src[3];
    uint16_t *temp[3];
    int outbuf_size;
    uint8_t *outbuf;
    AVCodecContext *avctx_enc[BLOCK*BLOCK];
    AVFrame *frame;
    AVFrame *frame_dec;
    uint8_t *non_b_qp_table;
    int non_b_qp_alloc_size;
    int use_bframe_qp;
} USPPContext;
#define OFFSET(x) offsetof(USPPContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define STORE(pos) do {                                                     \

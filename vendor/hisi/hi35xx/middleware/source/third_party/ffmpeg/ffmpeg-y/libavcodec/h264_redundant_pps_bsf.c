#include <string.h>
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_h264.h"
#include "h264.h"
typedef struct H264RedundantPPSContext {
    CodedBitstreamContext *input;
    CodedBitstreamContext *output;

    CodedBitstreamFragment access_unit;

    int global_pic_init_qp;
    int current_pic_init_qp;
    int extradata_pic_init_qp;
} H264RedundantPPSContext;

#include <nppi.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/common.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_cuda_internal.h"
#include "libavutil/cuda_check.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define CHECK_CU(x) FF_CUDA_CHECK_DL(ctx, device_hwctx->internal->cuda_dl, x)
typedef struct NPPTransposeStageContext {
    int stage_needed;
    enum AVPixelFormat in_fmt;
    enum AVPixelFormat out_fmt;
    struct {
        int width;
        int height;
    } planes_in[3], planes_out[3];
typedef struct NPPTransposeContext {
    const AVClass *class;
    NPPTransposeStageContext stages[STAGE_NB];
    AVFrame *tmp_frame;

    int passthrough;    ///< PassthroughType, landscape passthrough mode enabled
    int dir;            ///< TransposeDir
} NPPTransposeContext;
#define OFFSET(x) offsetof(NPPTransposeContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM)

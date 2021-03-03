#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_cuda_internal.h"
#include "libavutil/cuda_check.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#define CHECK_CU(x) FF_CUDA_CHECK_DL(ctx, s->hwctx->internal->cuda_dl, x)
#define HIST_SIZE (3*256)
#define DIV_UP(a, b) ( ((a) + (b) - 1) / (b) )
#define BLOCKX 32
#define BLOCKY 16
typedef struct ThumbnailCudaContext {
    const AVClass *class;
    int n;                      ///< current frame
    int n_frames;               ///< number of frames for analysis
    struct thumb_frame *frames; ///< the n_frames frames
    AVRational tb;              ///< copy of the input timebase to ease access

    AVBufferRef *hw_frames_ctx;
    AVCUDADeviceContext *hwctx;

    CUmodule    cu_module;

    CUfunction  cu_func_uchar;
    CUfunction  cu_func_uchar2;
    CUfunction  cu_func_ushort;
    CUfunction  cu_func_ushort2;
    CUstream    cu_stream;

    CUdeviceptr data;

} ThumbnailCudaContext;
#define OFFSET(x) offsetof(ThumbnailCudaContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

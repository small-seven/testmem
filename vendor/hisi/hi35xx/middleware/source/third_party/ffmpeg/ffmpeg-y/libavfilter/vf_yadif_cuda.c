#include "libavutil/avassert.h"
#include "libavutil/hwcontext_cuda_internal.h"
#include "libavutil/cuda_check.h"
#include "internal.h"
#include "yadif.h"
typedef struct DeintCUDAContext {
    YADIFContext yadif;

    AVCUDADeviceContext *hwctx;
    AVBufferRef         *device_ref;
    AVBufferRef         *input_frames_ref;
    AVHWFramesContext   *input_frames;

    CUcontext   cu_ctx;
    CUstream    stream;
    CUmodule    cu_module;
    CUfunction  cu_func_uchar;
    CUfunction  cu_func_uchar2;
    CUfunction  cu_func_ushort;
    CUfunction  cu_func_ushort2;
} DeintCUDAContext;
#define DIV_UP(a, b) ( ((a) + (b) - 1) / (b) )
#define ALIGN_UP(a, b) (((a) + (b) - 1) & ~((b) - 1))
#define BLOCKX 32
#define BLOCKY 16
#define CHECK_CU(x) FF_CUDA_CHECK_DL(ctx, s->hwctx->internal->cuda_dl, x)

#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "hwcontext_cuda_internal.h"
#include "cuda_check.h"
#include "mem.h"
#include "pixdesc.h"
#include "pixfmt.h"
#include "imgutils.h"
#define CUDA_FRAME_ALIGNMENT 256
typedef struct CUDAFramesContext {
    int shift_width, shift_height;
} CUDAFramesContext;
#define CHECK_CU(x) FF_CUDA_CHECK_DL(device_ctx, cu, x)
static void cuda_buffer_free(void *opaque, uint8_t *data)
{
    AVHWFramesContext        *ctx = opaque;
    AVHWDeviceContext *device_ctx = ctx->device_ctx;
    AVCUDADeviceContext    *hwctx = device_ctx->hwctx;
    CudaFunctions             *cu = hwctx->internal->cuda_dl;

    CUcontext dummy;

    CHECK_CU(cu->cuCtxPushCurrent(hwctx->cuda_ctx));

    CHECK_CU(cu->cuMemFree((CUdeviceptr)data));

    CHECK_CU(cu->cuCtxPopCurrent(&dummy));
}

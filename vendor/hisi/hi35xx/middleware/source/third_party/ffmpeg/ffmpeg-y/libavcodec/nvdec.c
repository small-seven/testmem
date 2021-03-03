#include "config.h"
#include "libavutil/common.h"
#include "libavutil/error.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_cuda_internal.h"
#include "libavutil/cuda_check.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#include "avcodec.h"
#include "decode.h"
#include "nvdec.h"
#include "internal.h"
#if !NVDECAPI_CHECK_VERSION(9, 0)
#define cudaVideoSurfaceFormat_YUV444 2
#define cudaVideoSurfaceFormat_YUV444_16Bit 3
#endif
typedef struct NVDECDecoder {
    CUvideodecoder decoder;

    AVBufferRef *hw_device_ref;
    CUcontext    cuda_ctx;
    CUstream     stream;

    CudaFunctions *cudl;
    CuvidFunctions *cvdl;
} NVDECDecoder;
typedef struct NVDECFramePool {
    unsigned int dpb_size;
    unsigned int nb_allocated;
} NVDECFramePool;
#define CHECK_CU(x) FF_CUDA_CHECK_DL(logctx, decoder->cudl, x)
#if defined(_WIN32) || defined(__CYGWIN__)
#else
#endif
static void nvdec_decoder_free(void *opaque, uint8_t *data)
{
    NVDECDecoder *decoder = (NVDECDecoder*)data;

    if (decoder->decoder) {
        void *logctx = decoder->hw_device_ref->data;
        CUcontext dummy;
        CHECK_CU(decoder->cudl->cuCtxPushCurrent(decoder->cuda_ctx));
        CHECK_CU(decoder->cvdl->cuvidDestroyDecoder(decoder->decoder));
        CHECK_CU(decoder->cudl->cuCtxPopCurrent(&dummy));
    }

    av_buffer_unref(&decoder->hw_device_ref);

    cuvid_free_functions(&decoder->cvdl);

    av_freep(&decoder);
}
static void nvdec_fdd_priv_free(void *priv)
{
    NVDECFrame *cf = priv;

    if (!cf)
        return;

    av_buffer_unref(&cf->idx_ref);
    av_buffer_unref(&cf->decoder_ref);

    av_freep(&priv);
}

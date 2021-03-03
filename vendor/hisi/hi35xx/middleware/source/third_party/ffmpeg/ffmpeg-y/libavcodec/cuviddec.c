#include "compat/cuda/dynlink_loader.h"
#include "libavutil/buffer.h"
#include "libavutil/mathematics.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_cuda_internal.h"
#include "libavutil/cuda_check.h"
#include "libavutil/fifo.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "decode.h"
#include "hwaccel.h"
#include "nvdec.h"
#include "internal.h"
#if !NVDECAPI_CHECK_VERSION(9, 0)
#define cudaVideoSurfaceFormat_YUV444 2
#define cudaVideoSurfaceFormat_YUV444_16Bit 3
#endif
typedef struct CuvidContext
{
    AVClass *avclass;

    CUvideodecoder cudecoder;
    CUvideoparser cuparser;

    char *cu_gpu;
    int nb_surfaces;
    int drop_second_field;
    char *crop_expr;
    char *resize_expr;

    struct {
        int left;
        int top;
        int right;
        int bottom;
    } crop;
typedef struct CuvidParsedFrame
{
    CUVIDPARSERDISPINFO dispinfo;
    int second_field;
    int is_deinterlacing;
} CuvidParsedFrame;
#define CHECK_CU(x) FF_CUDA_CHECK_DL(avctx, ctx->cudl, x)
#if FF_API_PKT_PTS
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#else
#endif
#if CONFIG_H264_CUVID_DECODER
#endif
#if CONFIG_HEVC_CUVID_DECODER
#endif
#if CONFIG_MJPEG_CUVID_DECODER
#endif
#if CONFIG_MPEG1_CUVID_DECODER
#endif
#if CONFIG_MPEG2_CUVID_DECODER
#endif
#if CONFIG_MPEG4_CUVID_DECODER
#endif
#if CONFIG_VP8_CUVID_DECODER
#endif
#if CONFIG_VP9_CUVID_DECODER
#endif
#if CONFIG_VC1_CUVID_DECODER
#endif
#define OFFSET(x) offsetof(CuvidContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#define DEFINE_CUVID_CODEC(x, X) \
#if CONFIG_HEVC_CUVID_DECODER
#endif
#if CONFIG_H264_CUVID_DECODER
#endif
#if CONFIG_MJPEG_CUVID_DECODER
#endif
#if CONFIG_MPEG1_CUVID_DECODER
#endif
#if CONFIG_MPEG2_CUVID_DECODER
#endif
#if CONFIG_MPEG4_CUVID_DECODER
#endif
#if CONFIG_VP8_CUVID_DECODER
#endif
#if CONFIG_VP9_CUVID_DECODER
#endif
#if CONFIG_VC1_CUVID_DECODER
#endif

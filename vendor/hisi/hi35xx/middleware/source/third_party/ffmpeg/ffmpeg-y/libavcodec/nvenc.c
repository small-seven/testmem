#include "config.h"
#include "nvenc.h"
#include "libavutil/hwcontext_cuda.h"
#include "libavutil/hwcontext.h"
#include "libavutil/cuda_check.h"
#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#define CHECK_CU(x) FF_CUDA_CHECK_DL(avctx, dl_fn->cuda_dl, x)
#define NVENC_CAP 0x30
#define IS_CBR(rc) (rc == NV_ENC_PARAMS_RC_CBR ||             \
#if CONFIG_D3D11VA
#endif
#define IS_10BIT(pix_fmt)  (pix_fmt == AV_PIX_FMT_P010    || \
#define IS_YUV444(pix_fmt) (pix_fmt == AV_PIX_FMT_YUV444P || \
#if NVENCAPI_CHECK_VERSION(9, 2)
#elif NVENCAPI_CHECK_VERSION(9, 1)
# if defined(_WIN32) || defined(__CYGWIN__)
# else
# endif
#elif NVENCAPI_CHECK_VERSION(9, 0)
# if defined(_WIN32) || defined(__CYGWIN__)
# else
# endif
#elif NVENCAPI_CHECK_VERSION(8, 2)
# if defined(_WIN32) || defined(__CYGWIN__)
# else
#endif
#elif NVENCAPI_CHECK_VERSION(8, 1)
# if defined(_WIN32) || defined(__CYGWIN__)
# else
# endif
#else
# if defined(_WIN32) || defined(__CYGWIN__)
# else
# endif
#endif
#ifdef NVENC_HAVE_BFRAME_REF_MODE
#else
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_D3D11VA
#endif
typedef struct GUIDTuple {
    const GUID guid;
    int flags;
} GUIDTuple;
#define PRESET_ALIAS(alias, name, ...) \
#define PRESET(name, ...) PRESET_ALIAS(name, name, __VA_ARGS__)
#undef PRESET
#undef PRESET_ALIAS
#ifdef NVENC_HAVE_BFRAME_REF_MODE
#endif
#ifdef NVENC_HAVE_HEVC_BFRAME_REF_MODE
#endif
#if CONFIG_D3D11VA
#endif
#if FF_API_CODED_FRAME
#endif

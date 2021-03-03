#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/hwcontext.h"
#if CONFIG_D3D11VA
#include "libavutil/hwcontext_d3d11va.h"
#endif
#if CONFIG_DXVA2
#define COBJMACROS
#include "libavutil/hwcontext_dxva2.h"
#endif
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time.h"
#include "amfenc.h"
#include "internal.h"
#if CONFIG_D3D11VA
#include <d3d11.h>
#endif
#ifdef _WIN32
#include "compat/w32dlfcn.h"
#else
#include <dlfcn.h>
#endif
#define FFMPEG_AMF_WRITER_ID L"ffmpeg_amf"
#define PTS_PROP L"PtsProp"
#if CONFIG_D3D11VA
#endif
#if CONFIG_DXVA2
#endif
typedef struct FormatMap {
    enum AVPixelFormat       av_format;
    enum AMF_SURFACE_FORMAT  amf_format;
} FormatMap;
#if CONFIG_D3D11VA
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_DXVA2
#endif
#if CONFIG_D3D11VA
#endif
#if CONFIG_DXVA2
#endif

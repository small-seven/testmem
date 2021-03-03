#include "config.h"
#include "videotoolbox.h"
#include "libavutil/hwcontext_videotoolbox.h"
#include "vt_internal.h"
#include "libavutil/avutil.h"
#include "libavutil/hwcontext.h"
#include "libavutil/pixdesc.h"
#include "bytestream.h"
#include "decode.h"
#include "h264dec.h"
#include "hevcdec.h"
#include "mpegvideo.h"
#include <TargetConditionals.h>
#ifndef kVTVideoDecoderSpecification_RequireHardwareAcceleratedVideoDecoder
#  define kVTVideoDecoderSpecification_RequireHardwareAcceleratedVideoDecoder CFSTR("RequireHardwareAcceleratedVideoDecoder")
#endif
#ifndef kVTVideoDecoderSpecification_EnableHardwareAcceleratedVideoDecoder
#  define kVTVideoDecoderSpecification_EnableHardwareAcceleratedVideoDecoder CFSTR("EnableHardwareAcceleratedVideoDecoder")
#endif
#if !HAVE_KCMVIDEOCODECTYPE_HEVC
#endif
#define VIDEOTOOLBOX_ESDS_EXTRADATA_PADDING  12
typedef struct VTHWFrame {
    CVPixelBufferRef pixbuf;
    AVBufferRef *hw_frames_ctx;
} VTHWFrame;
#define AV_W8(p, v) *(p) = (v)
#define COUNT_SIZE_PS(T, t) \
#define APPEND_PS(T, t) \
#if CONFIG_VIDEOTOOLBOX
#if TARGET_OS_IPHONE
#else
#endif
void av_videotoolbox_default_free(AVCodecContext *avctx)
{

    videotoolbox_stop(avctx);
    av_freep(&avctx->hwaccel_context);
}
#endif /* CONFIG_VIDEOTOOLBOX */

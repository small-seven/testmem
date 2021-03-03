#include "config.h"
#if HAVE_UTGETOSTYPEFROMSTRING
#include <CoreServices/CoreServices.h>
#endif
#include "libavcodec/avcodec.h"
#include "libavcodec/videotoolbox.h"
#include "libavutil/imgutils.h"
#include "ffmpeg.h"
typedef struct VTContext {
    AVFrame *tmp_frame;
} VTContext;
#ifdef kCFCoreFoundationVersionNumber10_7
#endif
#if HAVE_KCVPIXELFORMATTYPE_420YPCBCR10BIPLANARVIDEORANGE
#endif
#if HAVE_UTGETOSTYPEFROMSTRING
#else
#endif

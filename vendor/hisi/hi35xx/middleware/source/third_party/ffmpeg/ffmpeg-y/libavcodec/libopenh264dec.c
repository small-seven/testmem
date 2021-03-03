#include <wels/codec_api.h>
#include <wels/codec_ver.h>
#include "libavutil/common.h"
#include "libavutil/fifo.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "libopenh264.h"
typedef struct SVCContext {
    ISVCDecoder *decoder;
} SVCContext;
#if !OPENH264_VER_AT_LEAST(1, 6)
#endif
#if OPENH264_VER_AT_LEAST(1, 7)
#endif
#if OPENH264_VER_AT_LEAST(1, 9)
#else
#endif
#if OPENH264_VER_AT_LEAST(1, 4)
#else
#endif
#if FF_API_PKT_PTS
#endif
#if OPENH264_VER_AT_LEAST(1, 7)
#endif

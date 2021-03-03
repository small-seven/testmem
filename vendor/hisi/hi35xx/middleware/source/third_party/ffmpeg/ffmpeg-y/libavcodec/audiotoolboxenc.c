#include <AudioToolbox/AudioToolbox.h>
#define FF_BUFQUEUE_SIZE 256
#include "libavfilter/bufferqueue.h"
#include "config.h"
#include "audio_frame_queue.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libavformat/isom.h"
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
typedef struct ATDecodeContext {
    AVClass *av_class;
    int mode;
    int quality;

    AudioConverterRef converter;
    struct FFBufQueue frame_queue;
    struct FFBufQueue used_frame_queue;

    unsigned pkt_size;
    AudioFrameQueue afq;
    int eof;
    int frame_size;

    AVFrame* encoding_frame;
} ATDecodeContext;
#if !TARGET_OS_IPHONE
#endif
#if !TARGET_OS_IPHONE && defined(__MAC_10_9)
#endif
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if !TARGET_OS_IPHONE
#endif
#define FFAT_ENC_CLASS(NAME) \
#define FFAT_ENC(NAME, ID, PROFILES, ...) \

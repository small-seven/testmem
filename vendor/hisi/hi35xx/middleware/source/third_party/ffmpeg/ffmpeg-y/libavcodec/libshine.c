#include <shine/layer3.h>
#include "libavutil/intreadwrite.h"
#include "audio_frame_queue.h"
#include "avcodec.h"
#include "internal.h"
#include "mpegaudio.h"
#include "mpegaudiodecheader.h"
#define BUFFER_SIZE (4096 * 20)
typedef struct SHINEContext {
    shine_config_t  config;
    shine_t         shine;
    uint8_t         buffer[BUFFER_SIZE];
    int             buffer_index;
    AudioFrameQueue afq;
} SHINEContext;

#include "libavutil/channel_layout.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
typedef struct CinAudioContext {
    int initial_decode_frame;
    int delta;
} CinAudioContext;

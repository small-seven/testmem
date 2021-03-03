#include <speex/speex.h>
#include <speex/speex_header.h>
#include <speex/speex_stereo.h>
#include <speex/speex_callbacks.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "avcodec.h"
#include "internal.h"
typedef struct LibSpeexContext {
    SpeexBits bits;
    SpeexStereoState stereo;
    void *dec_state;
    int frame_size;
    int pktsize;
} LibSpeexContext;

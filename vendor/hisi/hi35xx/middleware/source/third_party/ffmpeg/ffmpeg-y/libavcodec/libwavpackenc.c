#include <wavpack/wavpack.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio_frame_queue.h"
#include "avcodec.h"
#include "internal.h"
#define WV_DEFAULT_BLOCK_SIZE 32768
typedef struct LibWavpackContext {
    const AVClass *class;
    WavpackContext *wv;
    AudioFrameQueue afq;

    AVPacket *pkt;
    int user_size;

    int got_output;
} LibWavpackContext;

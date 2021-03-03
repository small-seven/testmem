#include <lame/lame.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "audio_frame_queue.h"
#include "internal.h"
#include "mpegaudio.h"
#include "mpegaudiodecheader.h"
#define BUFFER_SIZE (7200 + 2 * MPA_FRAME_SIZE + MPA_FRAME_SIZE / 4+1000) // FIXME: Buffer size to small? Adding 1000 to make up for it.
typedef struct LAMEContext {
    AVClass *class;
    AVCodecContext *avctx;
    lame_global_flags *gfp;
    uint8_t *buffer;
    int buffer_index;
    int buffer_size;
    int reservoir;
    int joint_stereo;
    int abr;
    int delay_sent;
    float *samples_flt[2];
    AudioFrameQueue afq;
    AVFloatDSPContext *fdsp;
} LAMEContext;
#define ENCODE_BUFFER(func, buf_type, buf_name) do {                        \
#define OFFSET(x) offsetof(LAMEContext, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM

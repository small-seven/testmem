#include <speex/speex.h>
#include <speex/speex_header.h>
#include <speex/speex_stereo.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "audio_frame_queue.h"
typedef struct LibSpeexEncContext {
    AVClass *class;             ///< AVClass for private options
    SpeexBits bits;             ///< libspeex bitwriter context
    SpeexHeader header;         ///< libspeex header struct
    void *enc_state;            ///< libspeex encoder state
    int frames_per_packet;      ///< number of frames to encode in each packet
    float vbr_quality;          ///< VBR quality 0.0 to 10.0
    int cbr_quality;            ///< CBR quality 0 to 10
    int abr;                    ///< flag to enable ABR
    int vad;                    ///< flag to enable VAD
    int dtx;                    ///< flag to enable DTX
    int pkt_frame_count;        ///< frame count for the current packet
    AudioFrameQueue afq;        ///< frame queue
} LibSpeexEncContext;
#define OFFSET(x) offsetof(LibSpeexEncContext, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM

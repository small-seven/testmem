#include <fdk-aac/aacenc_lib.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "audio_frame_queue.h"
#include "internal.h"
#ifdef AACENCODER_LIB_VL0
#define FDKENC_VER_AT_LEAST(vl0, vl1) \
#else
#define FDKENC_VER_AT_LEAST(vl0, vl1) 0
#endif
typedef struct AACContext {
    const AVClass *class;
    HANDLE_AACENCODER handle;
    int afterburner;
    int eld_sbr;
    int eld_v2;
    int signaling;
    int latm;
    int header_period;
    int vbr;

    AudioFrameQueue afq;
} AACContext;
#if FDKENC_VER_AT_LEAST(4, 0) // 4.0.0
#endif
#if FDKENC_VER_AT_LEAST(4, 0) // 4.0.0
#endif
#if FDKENC_VER_AT_LEAST(3, 4) // 3.4.12
#endif
#if FDKENC_VER_AT_LEAST(4, 0) // 4.0.0
#else
#endif
#if FDKENC_VER_AT_LEAST(3, 4) // 3.4.12
#endif

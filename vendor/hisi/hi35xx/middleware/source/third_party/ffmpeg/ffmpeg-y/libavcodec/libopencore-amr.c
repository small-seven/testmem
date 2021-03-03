#include <inttypes.h>
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "audio_frame_queue.h"
#include "internal.h"
#if CONFIG_LIBOPENCORE_AMRNB
#include <opencore-amrnb/interf_dec.h>
#include <opencore-amrnb/interf_enc.h>
typedef struct AMRContext {
    AVClass *av_class;
    void *dec_state;
    void *enc_state;
    int   enc_bitrate;
    int   enc_mode;
    int   enc_dtx;
    int   enc_last_frame;
    AudioFrameQueue afq;
} AMRContext;
#if CONFIG_LIBOPENCORE_AMRNB_DECODER
#endif /* CONFIG_LIBOPENCORE_AMRNB_DECODER */
#if CONFIG_LIBOPENCORE_AMRNB_ENCODER
typedef struct AMR_bitrates {
    int       rate;
    enum Mode mode;
} AMR_bitrates;
#endif /* CONFIG_LIBOPENCORE_AMRNB_ENCODER */
#endif /* CONFIG_LIBOPENCORE_AMRNB */
#if CONFIG_LIBOPENCORE_AMRWB_DECODER
#include <opencore-amrwb/dec_if.h>
#include <opencore-amrwb/if_rom.h>
typedef struct AMRWBContext {
    void  *state;
} AMRWBContext;
#endif /* CONFIG_LIBOPENCORE_AMRWB_DECODER */

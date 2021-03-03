#include <fdk-aac/aacdecoder_lib.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#ifdef AACDECODER_LIB_VL0
#define FDKDEC_VER_AT_LEAST(vl0, vl1) \
#else
#define FDKDEC_VER_AT_LEAST(vl0, vl1) 0
#endif
#if !FDKDEC_VER_AT_LEAST(2, 5) // < 2.5.10
#define AAC_PCM_MAX_OUTPUT_CHANNELS AAC_PCM_OUTPUT_CHANNELS
#endif
typedef struct FDKAACDecContext {
    const AVClass *class;
    HANDLE_AACDECODER handle;
    uint8_t *decoder_buffer;
    int decoder_buffer_size;
    uint8_t *anc_buffer;
    int conceal_method;
    int drc_level;
    int drc_boost;
    int drc_heavy;
    int drc_effect;
    int drc_cut;
    int level_limit;
} FDKAACDecContext;
#define DMX_ANC_BUFFSIZE       128
#define DECODER_MAX_CHANNELS     8
#define DECODER_BUFFSIZE      2048 * sizeof(INT_PCM)
#define OFFSET(x) offsetof(FDKAACDecContext, x)
#define AD AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#if FDKDEC_VER_AT_LEAST(2, 5) // 2.5.10
#endif
#if FDKDEC_VER_AT_LEAST(3, 0) // 3.0.0
#endif
#if FDKDEC_VER_AT_LEAST(2, 5) // 2.5.10
#endif
#if FDKDEC_VER_AT_LEAST(3, 0) // 3.0.0
#endif

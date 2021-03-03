#include <gme/gme.h>
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
typedef struct GMEContext {
    const AVClass *class;
    Music_Emu *music_emu;
    gme_info_t *info;   ///< selected track

    /* options */
    int track_index;
    int sample_rate;
    int64_t max_size;
} GMEContext;
#define OFFSET(x) offsetof(GMEContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
#define AUDIO_PKT_SIZE 512

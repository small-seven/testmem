#include <flite/flite.h>
#include "libavutil/channel_layout.h"
#include "libavutil/file.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "internal.h"
typedef struct FliteContext {
    const AVClass *class;
    char *voice_str;
    char *textfile;
    char *text;
    cst_wave *wave;
    int16_t *wave_samples;
    int      wave_nb_samples;
    int list_voices;
    cst_voice *voice;
    struct voice_entry *voice_entry;
    int64_t pts;
    int frame_nb_samples; ///< number of samples per frame
} FliteContext;
#define OFFSET(x) offsetof(FliteContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define DECLARE_REGISTER_VOICE_FN(name) \
#define MAKE_VOICE_STRUCTURE(voice_name) {             \

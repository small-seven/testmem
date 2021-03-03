#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#include "generate_wave_table.h"
typedef struct VibratoContext {
    const AVClass *class;
    double freq;
    double depth;
    int channels;

    double **buf;
    int buf_index;
    int buf_size;

    double *wave_table;
    int wave_table_index;
    int wave_table_size;
} VibratoContext;
#define OFFSET(x) offsetof(VibratoContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

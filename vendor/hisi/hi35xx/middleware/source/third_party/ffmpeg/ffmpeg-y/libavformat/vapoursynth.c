#include <limits.h>
#include <VapourSynth.h>
#include <VSScript.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avformat.h"
#include "internal.h"
typedef struct VSContext {
    const AVClass *class;

    AVBufferRef *vss_state;

    const VSAPI *vsapi;
    VSCore *vscore;

    VSNodeRef *outnode;
    int is_cfr;
    int current_frame;

    int c_order[4];

    /* options */
    int64_t max_script_size;
} VSContext;
#define OFFSET(x) offsetof(VSContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM

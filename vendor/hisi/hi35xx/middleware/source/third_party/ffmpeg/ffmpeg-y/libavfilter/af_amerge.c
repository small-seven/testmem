#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "audio.h"
#include "internal.h"
#define SWR_CH_MAX 64
typedef struct AMergeContext {
    const AVClass *class;
    int nb_inputs;
    int route[SWR_CH_MAX]; /**< channels routing, see copy_samples */
    int bps;
    struct amerge_input {
        int nb_ch;         /**< number of channels for the input */
    } *in;
#define OFFSET(x) offsetof(AMergeContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM

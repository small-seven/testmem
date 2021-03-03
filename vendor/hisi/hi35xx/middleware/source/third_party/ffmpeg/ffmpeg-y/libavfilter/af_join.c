#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "filters.h"
#include "internal.h"
typedef struct ChannelMap {
    int input;                ///< input stream index
    int       in_channel_idx; ///< index of in_channel in the input stream data
    uint64_t  in_channel;     ///< layout describing the input channel
    uint64_t out_channel;     ///< layout describing the output channel
} ChannelMap;
typedef struct JoinContext {
    const AVClass *class;

    int inputs;
    char *map;
    char    *channel_layout_str;
    uint64_t channel_layout;

    int      nb_channels;
    ChannelMap *channels;

    /**
     * Temporary storage for input frames, until we get one on each input.
     */
    AVFrame **input_frames;

    /**
     *  Temporary storage for buffer references, for assembling the output frame.
     */
    AVBufferRef **buffers;
} JoinContext;
#define OFFSET(x) offsetof(JoinContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define PARSE_CHANNEL(str, var, inout)                                         \

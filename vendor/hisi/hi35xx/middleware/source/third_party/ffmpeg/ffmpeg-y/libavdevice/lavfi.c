#include <float.h>              /* DBL_MIN, DBL_MAX */
#include "libavutil/bprint.h"
#include "libavutil/channel_layout.h"
#include "libavutil/file.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavfilter/avfilter.h"
#include "libavfilter/buffersink.h"
#include "libavformat/avio_internal.h"
#include "libavformat/internal.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;          ///< class for private options
    char          *graph_str;
    char          *graph_filename;
    char          *dump_graph;
    AVFilterGraph *graph;
    AVFilterContext **sinks;
    int *sink_stream_map;
    int *sink_eof;
    int *stream_sink_map;
    int *sink_stream_subcc_map;
    AVFrame *decoded_frame;
    int nb_sinks;
    AVPacket subcc_packet;
} LavfiContext;
#define FAIL(ERR) { ret = ERR; goto end; }
#define OFFSET(x) offsetof(LavfiContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM

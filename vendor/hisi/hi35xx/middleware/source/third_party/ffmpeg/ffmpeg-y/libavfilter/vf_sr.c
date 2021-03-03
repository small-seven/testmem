#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavformat/avio.h"
#include "libswscale/swscale.h"
#include "dnn_interface.h"
typedef struct SRContext {
    const AVClass *class;

    char *model_filename;
    DNNBackendType backend_type;
    DNNModule *dnn_module;
    DNNModel *model;
    DNNInputData input;
    DNNData output;
    int scale_factor;
    struct SwsContext *sws_contexts[3];
    int sws_slice_h, sws_input_linesize, sws_output_linesize;
} SRContext;
#define OFFSET(x) offsetof(SRContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#if (CONFIG_LIBTENSORFLOW == 1)
#endif

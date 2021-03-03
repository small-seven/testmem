#include "libavformat/avio.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "dnn_interface.h"
#include "formats.h"
#include "internal.h"
typedef struct DRContext {
    const AVClass *class;

    char              *model_filename;
    DNNBackendType     backend_type;
    DNNModule         *dnn_module;
    DNNModel          *model;
    DNNInputData       input;
    DNNData            output;
} DRContext;
#define CLIP(x, min, max) (x < min ? min : (x > max ? max : x))
#define OFFSET(x) offsetof(DRContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#if (CONFIG_LIBTENSORFLOW == 1)
#endif

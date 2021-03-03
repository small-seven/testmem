#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
typedef struct FieldContext {
    const AVClass *class;
    int type;                   ///< FieldType
    int nb_planes;              ///< number of planes of the current format
} FieldContext;
#define OFFSET(x) offsetof(FieldContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM

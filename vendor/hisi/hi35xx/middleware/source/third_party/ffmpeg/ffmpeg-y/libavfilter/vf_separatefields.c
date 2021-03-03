#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
typedef struct SeparateFieldsContext {
    int nb_planes;
    AVFrame *second;
} SeparateFieldsContext;

#include <stdlib.h>
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
typedef struct FilterUnitsContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment fragment;

    const char *pass_types;
    const char *remove_types;

    enum {
        NOOP,
        PASS,
        REMOVE,
    } mode;
#define OFFSET(x) offsetof(FilterUnitsContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)

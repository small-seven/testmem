#include <stdio.h>
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/log.h"
#include "bsf.h"
#include "cbs.h"
typedef struct TraceHeadersContext {
    CodedBitstreamContext *cbc;
    CodedBitstreamFragment fragment;
} TraceHeadersContext;

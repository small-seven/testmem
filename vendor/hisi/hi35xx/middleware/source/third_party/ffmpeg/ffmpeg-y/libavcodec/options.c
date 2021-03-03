#include "avcodec.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include <string.h>
#include "options_table.h"
#if FF_API_GET_CONTEXT_DEFAULTS
#endif
#if FF_API_COPY_CONTEXT
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#define alloc_and_copy_or_fail(obj, size, pad) \
#undef alloc_and_copy_or_fail
#endif
#define FOFFSET(x) offsetof(AVFrame,x)
#define SROFFSET(x) offsetof(AVSubtitleRect,x)

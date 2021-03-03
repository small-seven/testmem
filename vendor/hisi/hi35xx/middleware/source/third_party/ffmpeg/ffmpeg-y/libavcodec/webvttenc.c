#include <stdarg.h>
#include "avcodec.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "ass_split.h"
#include "ass.h"
#define WEBVTT_STACK_SIZE 64
typedef struct {
    AVCodecContext *avctx;
    ASSSplitContext *ass_ctx;
    AVBPrint buffer;
    unsigned timestamp_end;
    int count;
    char stack[WEBVTT_STACK_SIZE];
    int stack_ptr;
} WebVTTContext;
#ifdef __GNUC__
#endif
#if FF_API_ASS_TIMING
#endif
#if FF_API_ASS_TIMING
#endif

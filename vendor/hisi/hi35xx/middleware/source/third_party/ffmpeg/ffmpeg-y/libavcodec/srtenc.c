#include <stdarg.h>
#include "avcodec.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "ass_split.h"
#include "ass.h"
#define SRT_STACK_SIZE 64
typedef struct {
    AVCodecContext *avctx;
    ASSSplitContext *ass_ctx;
    AVBPrint buffer;
    char stack[SRT_STACK_SIZE];
    int stack_ptr;
    int alignment_applied;
} SRTContext;
#ifdef __GNUC__
#endif
#if FF_API_ASS_TIMING
#endif
#if FF_API_ASS_TIMING
#endif
#if CONFIG_SRT_ENCODER
#endif
#if CONFIG_SUBRIP_ENCODER
#endif
#if CONFIG_TEXT_ENCODER
#endif

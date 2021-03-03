#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/ac3.h"
#include "libavcodec/ac3dsp.h"
#define DOWNMIX_FUNC_OPT(ch, opt)                                       \
#define DOWNMIX_FUNCS(opt)   \
#define SET_DOWNMIX(ch, suf, SUF)                                       \
#define SET_DOWNMIX_ALL(suf, SUF)                   \

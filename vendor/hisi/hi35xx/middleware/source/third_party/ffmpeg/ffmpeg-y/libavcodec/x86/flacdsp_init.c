#include "libavcodec/flacdsp.h"
#include "libavutil/x86/cpu.h"
#include "config.h"
#define DECORRELATE_FUNCS(fmt, opt)                                                      \
#if HAVE_X86ASM
#if CONFIG_FLAC_DECODER
#endif
#if CONFIG_FLAC_ENCODER
#endif
#endif /* HAVE_X86ASM */

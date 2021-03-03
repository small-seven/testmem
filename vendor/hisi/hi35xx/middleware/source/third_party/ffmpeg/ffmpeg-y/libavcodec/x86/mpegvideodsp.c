#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/mpegvideodsp.h"
#include "libavcodec/videodsp.h"
#if HAVE_INLINE_ASM
#define MAX_STRIDE 4096U
#define MAX_H 8U
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#endif /* HAVE_INLINE_ASM */

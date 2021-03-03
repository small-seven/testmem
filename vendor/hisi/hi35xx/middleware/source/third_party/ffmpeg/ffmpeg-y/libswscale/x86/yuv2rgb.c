#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "config.h"
#include "libswscale/rgb2rgb.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/attributes.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavutil/cpu.h"
#if HAVE_INLINE_ASM
#define DITHER1XBPP // only for MMX
#if HAVE_MMX_INLINE && HAVE_6REGS
#undef RENAME
#undef COMPILE_TEMPLATE_MMXEXT
#define COMPILE_TEMPLATE_MMXEXT 0
#define RENAME(a) a ## _mmx
#include "yuv2rgb_template.c"
#endif /* HAVE_MMX_INLINE && HAVE_6REGS */
#if HAVE_MMXEXT_INLINE && HAVE_6REGS
#undef RENAME
#undef COMPILE_TEMPLATE_MMXEXT
#define COMPILE_TEMPLATE_MMXEXT 1
#define RENAME(a) a ## _mmxext
#include "yuv2rgb_template.c"
#endif /* HAVE_MMXEXT_INLINE && HAVE_6REGS */
#endif /* HAVE_INLINE_ASM */
#if HAVE_MMX_INLINE && HAVE_6REGS
#if HAVE_MMXEXT_INLINE
#endif
#if HAVE_7REGS && CONFIG_SWSCALE_ALPHA
#endif
#if HAVE_7REGS && CONFIG_SWSCALE_ALPHA
#endif
#endif /* HAVE_MMX_INLINE  && HAVE_6REGS */

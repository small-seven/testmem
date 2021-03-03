#include <stdint.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/x86/cpu.h"
#include "libavutil/cpu.h"
#include "libavutil/bswap.h"
#include "libswscale/rgb2rgb.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#if HAVE_INLINE_ASM
#define mask16b mask15b
#define BY ((int)( 0.098*(1<<RGB2YUV_SHIFT)+0.5))
#define BV ((int)(-0.071*(1<<RGB2YUV_SHIFT)+0.5))
#define BU ((int)( 0.439*(1<<RGB2YUV_SHIFT)+0.5))
#define GY ((int)( 0.504*(1<<RGB2YUV_SHIFT)+0.5))
#define GV ((int)(-0.368*(1<<RGB2YUV_SHIFT)+0.5))
#define GU ((int)(-0.291*(1<<RGB2YUV_SHIFT)+0.5))
#define RY ((int)( 0.257*(1<<RGB2YUV_SHIFT)+0.5))
#define RV ((int)( 0.439*(1<<RGB2YUV_SHIFT)+0.5))
#define RU ((int)(-0.148*(1<<RGB2YUV_SHIFT)+0.5))
#define COMPILE_TEMPLATE_MMXEXT 0
#define COMPILE_TEMPLATE_AMD3DNOW 0
#define COMPILE_TEMPLATE_SSE2 0
#define COMPILE_TEMPLATE_AVX 0
#undef RENAME
#define RENAME(a) a ## _mmx
#include "rgb2rgb_template.c"
#undef RENAME
#undef COMPILE_TEMPLATE_MMXEXT
#define COMPILE_TEMPLATE_MMXEXT 1
#define RENAME(a) a ## _mmxext
#include "rgb2rgb_template.c"
#undef RENAME
#undef COMPILE_TEMPLATE_SSE2
#define COMPILE_TEMPLATE_SSE2 1
#define RENAME(a) a ## _sse2
#include "rgb2rgb_template.c"
#undef RENAME
#undef COMPILE_TEMPLATE_AVX
#define COMPILE_TEMPLATE_AVX 1
#define RENAME(a) a ## _avx
#include "rgb2rgb_template.c"
#undef RENAME
#undef COMPILE_TEMPLATE_MMXEXT
#undef COMPILE_TEMPLATE_SSE2
#undef COMPILE_TEMPLATE_AVX
#undef COMPILE_TEMPLATE_AMD3DNOW
#define COMPILE_TEMPLATE_MMXEXT 0
#define COMPILE_TEMPLATE_SSE2 0
#define COMPILE_TEMPLATE_AVX 0
#define COMPILE_TEMPLATE_AMD3DNOW 1
#define RENAME(a) a ## _3dnow
#include "rgb2rgb_template.c"
#endif /* HAVE_INLINE_ASM */
#if ARCH_X86_64
#endif
#if HAVE_INLINE_ASM
#endif /* HAVE_INLINE_ASM */
#if ARCH_X86_64
#endif
#if ARCH_X86_64
#endif

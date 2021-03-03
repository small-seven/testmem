#include <stdint.h>
#include "libavutil/x86/asm.h"
#include "libswscale/swscale_internal.h"
#undef MOVNTQ
#undef EMMS
#undef SFENCE
#if COMPILE_TEMPLATE_MMXEXT
#define MOVNTQ "movntq"
#define SFENCE "sfence"
#else
#define MOVNTQ "movq"
#define SFENCE " # nop"
#endif
#define REG_BLUE  "0"
#define REG_RED   "1"
#define REG_GREEN "2"
#define REG_ALPHA "3"
#define YUV2RGB_LOOP(depth)                                          \
#define YUV2RGB_INITIAL_LOAD          \
#define YUV2RGB                                  \
#define RGB_PACK_INTERLEAVE                  \
#define YUV2RGB_ENDLOOP(depth)                   \
#if COMPILE_TEMPLATE_MMXEXT
#undef RGB_PACK24_B_OPERANDS
#define RGB_PACK24_B_OPERANDS NAMED_CONSTRAINTS_ARRAY_ADD(mask1101,mask0110,mask0100,mask0010,mask1001)
#else
#undef RGB_PACK24_B_OPERANDS
#define RGB_PACK24_B_OPERANDS
#endif
#define YUV2RGB_OPERANDS                                          \
#define YUV2RGB_OPERANDS_ALPHA                                    \
#define YUV2RGB_ENDFUNC                          \
#define IF0(x)
#define IF1(x) x
#define RGB_PACK16(gmask, is15)                  \
#define DITHER_RGB                               \
#if !COMPILE_TEMPLATE_MMXEXT
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#endif /* !COMPILE_TEMPLATE_MMXEXT */
#define RGB_PACK24(blue, red)\
#if COMPILE_TEMPLATE_MMXEXT
#undef RGB_PACK24_B
#define RGB_PACK24_B\
#else
#undef RGB_PACK24_B
#define RGB_PACK24_B\
#endif
#define SET_EMPTY_ALPHA                                                      \
#define LOAD_ALPHA                                   \
#define RGB_PACK32(red, green, blue, alpha)  \
#if !COMPILE_TEMPLATE_MMXEXT
#if HAVE_7REGS && CONFIG_SWSCALE_ALPHA
#endif
#if HAVE_7REGS && CONFIG_SWSCALE_ALPHA
#endif
#endif /* !COMPILE_TEMPLATE_MMXEXT */

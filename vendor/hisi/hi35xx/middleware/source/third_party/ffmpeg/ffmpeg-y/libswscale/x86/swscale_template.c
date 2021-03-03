#include <stdint.h>
#include "libavutil/x86/asm.h"
#include "libswscale/swscale_internal.h"
#undef REAL_MOVNTQ
#undef MOVNTQ
#undef MOVNTQ2
#undef PREFETCH
#if COMPILE_TEMPLATE_MMXEXT
#define REAL_MOVNTQ(a,b) "movntq " #a ", " #b " \n\t"
#define MOVNTQ2 "movntq "
#else
#define REAL_MOVNTQ(a,b) "movq " #a ", " #b " \n\t"
#define MOVNTQ2 "movq "
#endif
#define MOVNTQ(a,b)  REAL_MOVNTQ(a,b)
#if !COMPILE_TEMPLATE_MMXEXT
#endif
#define YSCALEYUV2PACKEDX_UV \
#define YSCALEYUV2PACKEDX_YA(offset,coeff,src1,src2,dst1,dst2) \
#define YSCALEYUV2PACKEDX \
#define YSCALEYUV2PACKEDX_END                     \
#define YSCALEYUV2PACKEDX_ACCURATE_UV \
#define YSCALEYUV2PACKEDX_ACCURATE_YA(offset) \
#define YSCALEYUV2PACKEDX_ACCURATE \
#define YSCALEYUV2RGBX \
#define REAL_WRITEBGR32(dst, dstw, index, b, g, r, a, q0, q2, q3, t) \
#define WRITEBGR32(dst, dstw, index, b, g, r, a, q0, q2, q3, t)  REAL_WRITEBGR32(dst, dstw, index, b, g, r, a, q0, q2, q3, t)
#define REAL_WRITERGB16(dst, dstw, index) \
#define WRITERGB16(dst, dstw, index)  REAL_WRITERGB16(dst, dstw, index)
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#define REAL_WRITERGB15(dst, dstw, index) \
#define WRITERGB15(dst, dstw, index)  REAL_WRITERGB15(dst, dstw, index)
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#define WRITEBGR24MMX(dst, dstw, index) \
#define WRITEBGR24MMXEXT(dst, dstw, index) \
#if COMPILE_TEMPLATE_MMXEXT
#undef WRITEBGR24
#define WRITEBGR24(dst, dstw, index)  WRITEBGR24MMXEXT(dst, dstw, index)
#else
#undef WRITEBGR24
#define WRITEBGR24(dst, dstw, index)  WRITEBGR24MMX(dst, dstw, index)
#endif
#if HAVE_6REGS
#endif /* HAVE_6REGS */
#define REAL_WRITEYUY2(dst, dstw, index) \
#define WRITEYUY2(dst, dstw, index)  REAL_WRITEYUY2(dst, dstw, index)
#define REAL_YSCALEYUV2RGB_UV(index, c) \
#define REAL_YSCALEYUV2RGB_YA(index, c, b1, b2) \
#define REAL_YSCALEYUV2RGB_COEFF(c) \
#define YSCALEYUV2RGB_YA(index, c, b1, b2) REAL_YSCALEYUV2RGB_YA(index, c, b1, b2)
#define YSCALEYUV2RGB(index, c) \
#if ARCH_X86_64
#else
#endif
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#define REAL_YSCALEYUV2PACKED(index, c) \
#define YSCALEYUV2PACKED(index, c)  REAL_YSCALEYUV2PACKED(index, c)
#define REAL_YSCALEYUV2RGB1(index, c) \
#define YSCALEYUV2RGB1(index, c)  REAL_YSCALEYUV2RGB1(index, c)
#define REAL_YSCALEYUV2RGB1b(index, c) \
#define YSCALEYUV2RGB1b(index, c)  REAL_YSCALEYUV2RGB1b(index, c)
#define REAL_YSCALEYUV2RGB1_ALPHA(index) \
#define YSCALEYUV2RGB1_ALPHA(index) REAL_YSCALEYUV2RGB1_ALPHA(index)
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#ifdef DITHER1XBPP
#endif
#define REAL_YSCALEYUV2PACKED1(index, c) \
#define YSCALEYUV2PACKED1(index, c)  REAL_YSCALEYUV2PACKED1(index, c)
#define REAL_YSCALEYUV2PACKED1b(index, c) \
#define YSCALEYUV2PACKED1b(index, c)  REAL_YSCALEYUV2PACKED1b(index, c)
#if HAVE_6REGS
#endif
#if HAVE_6REGS
#endif
#if COMPILE_TEMPLATE_MMXEXT
#endif /* COMPILE_TEMPLATE_MMXEXT */
#if COMPILE_TEMPLATE_MMXEXT
#endif /* COMPILE_TEMPLATE_MMXEXT */

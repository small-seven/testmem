#include "libavutil/x86/asm.h"
#ifdef TEMPLATE_PP_C
#   define RENAME(a) a ## _C
#else
#   define TEMPLATE_PP_C 0
#endif
#ifdef TEMPLATE_PP_ALTIVEC
#   define RENAME(a) a ## _altivec
#else
#   define TEMPLATE_PP_ALTIVEC 0
#endif
#ifdef TEMPLATE_PP_MMX
#   define RENAME(a) a ## _MMX
#else
#   define TEMPLATE_PP_MMX 0
#endif
#ifdef TEMPLATE_PP_MMXEXT
#   undef  TEMPLATE_PP_MMX
#   define TEMPLATE_PP_MMX 1
#   define RENAME(a) a ## _MMX2
#else
#   define TEMPLATE_PP_MMXEXT 0
#endif
#ifdef TEMPLATE_PP_3DNOW
#   undef  TEMPLATE_PP_MMX
#   define TEMPLATE_PP_MMX 1
#   define RENAME(a) a ## _3DNow
#else
#   define TEMPLATE_PP_3DNOW 0
#endif
#ifdef TEMPLATE_PP_SSE2
#   undef  TEMPLATE_PP_MMX
#   define TEMPLATE_PP_MMX 1
#   undef  TEMPLATE_PP_MMXEXT
#   define TEMPLATE_PP_MMXEXT 1
#   define RENAME(a) a ## _SSE2
#else
#   define TEMPLATE_PP_SSE2 0
#endif
#undef REAL_PAVGB
#undef PAVGB
#undef PMINUB
#undef PMAXUB
#if   TEMPLATE_PP_MMXEXT
#define REAL_PAVGB(a,b) "pavgb " #a ", " #b " \n\t"
#elif TEMPLATE_PP_3DNOW
#define REAL_PAVGB(a,b) "pavgusb " #a ", " #b " \n\t"
#endif
#define PAVGB(a,b)  REAL_PAVGB(a,b)
#if   TEMPLATE_PP_MMXEXT
#define PMINUB(a,b,t) "pminub " #a ", " #b " \n\t"
#elif TEMPLATE_PP_MMX
#define PMINUB(b,a,t) \
#endif
#if   TEMPLATE_PP_MMXEXT
#define PMAXUB(a,b) "pmaxub " #a ", " #b " \n\t"
#elif TEMPLATE_PP_MMX
#define PMAXUB(a,b) \
#endif
#if TEMPLATE_PP_MMX
#if TEMPLATE_PP_MMXEXT
#else
#endif
#endif //TEMPLATE_PP_MMX
#if !TEMPLATE_PP_ALTIVEC
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#else //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_ALTIVEC
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#else //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if !TEMPLATE_PP_ALTIVEC
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if 0 //slightly more accurate and slightly slower
#endif //0
#elif TEMPLATE_PP_MMX
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#else //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_ALTIVEC
#if !TEMPLATE_PP_ALTIVEC
#if HAVE_7REGS && (TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW)
#undef REAL_FIND_MIN_MAX
#undef FIND_MIN_MAX
#if TEMPLATE_PP_MMXEXT
#define REAL_FIND_MIN_MAX(addr)\
#else
#define REAL_FIND_MIN_MAX(addr)\
#endif
#define FIND_MIN_MAX(addr)  REAL_FIND_MIN_MAX(addr)
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#define REAL_DERING_CORE(dst,src,ppsx,psx,sx,pplx,plx,lx,t0,t1) \
#define DERING_CORE(dst,src,ppsx,psx,sx,pplx,plx,lx,t0,t1) \
#else // HAVE_7REGS && (TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW)
#ifdef DEBUG_DERING_THRESHOLD
#endif
#ifdef DEBUG_DERING_THRESHOLD
#endif
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_ALTIVEC
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#else
#endif
#if TEMPLATE_PP_SSE2 || TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if TEMPLATE_PP_SSE2
#define REAL_DEINT_CUBIC(a,b,c,d,e)\
#else //TEMPLATE_PP_SSE2
#define REAL_DEINT_CUBIC(a,b,c,d,e)\
#endif //TEMPLATE_PP_SSE2
#define DEINT_CUBIC(a,b,c,d,e)  REAL_DEINT_CUBIC(a,b,c,d,e)
#if TEMPLATE_PP_SSE2
#endif
#undef REAL_DEINT_CUBIC
#else //TEMPLATE_PP_SSE2 || TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_SSE2 || TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#define REAL_DEINT_FF(a,b,c,d)\
#define DEINT_FF(a,b,c,d)  REAL_DEINT_FF(a,b,c,d)
#else //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if (TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#define REAL_DEINT_L5(t1,t2,a,b,c)\
#define DEINT_L5(t1,t2,a,b,c)  REAL_DEINT_L5(t1,t2,a,b,c)
#else //(TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#endif //(TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#if TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#else //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#endif //TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW
#if TEMPLATE_PP_MMX
#if TEMPLATE_PP_MMXEXT
#else // MMX without MMX2
#define REAL_MEDIAN(a,b,c)\
#define MEDIAN(a,b,c)  REAL_MEDIAN(a,b,c)
#endif //TEMPLATE_PP_MMXEXT
#else //TEMPLATE_PP_MMX
#endif //TEMPLATE_PP_MMX
#if TEMPLATE_PP_MMX
#endif //TEMPLATE_PP_MMX
#if !TEMPLATE_PP_ALTIVEC
#define FAST_L2_DIFF
#if (TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#ifdef L1_DIFF //needs mmx2
#else //L1_DIFF
#if defined (FAST_L2_DIFF)
#define REAL_L2_DIFF_CORE(a, b)\
#else //defined (FAST_L2_DIFF)
#define REAL_L2_DIFF_CORE(a, b)\
#endif //defined (FAST_L2_DIFF)
#define L2_DIFF_CORE(a, b)  REAL_L2_DIFF_CORE(a, b)
#endif //L1_DIFF
#else //(TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#endif //(TEMPLATE_PP_MMXEXT || TEMPLATE_PP_3DNOW) && HAVE_6REGS
#endif //TEMPLATE_PP_ALTIVEC
#if TEMPLATE_PP_MMX
#define NEXT\
#define PREV\
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#endif //TEMPLATE_PP_MMX
#undef REAL_SCALED_CPY
#undef SCALED_CPY
#if !TEMPLATE_PP_MMX || !HAVE_6REGS
#endif
#if TEMPLATE_PP_MMX && HAVE_6REGS
#if TEMPLATE_PP_MMXEXT
#define REAL_SCALED_CPY(src1, src2, dst1, dst2)                                                \
#else //TEMPLATE_PP_MMXEXT
#define REAL_SCALED_CPY(src1, src2, dst1, dst2)                                        \
#endif //TEMPLATE_PP_MMXEXT
#define SCALED_CPY(src1, src2, dst1, dst2)\
#else //TEMPLATE_PP_MMX && HAVE_6REGS
#endif //TEMPLATE_PP_MMX && HAVE_6REGS
#if TEMPLATE_PP_MMX && HAVE_6REGS
#define REAL_SIMPLE_CPY(src1, src2, dst1, dst2)                              \
#define SIMPLE_CPY(src1, src2, dst1, dst2)\
#else //TEMPLATE_PP_MMX && HAVE_6REGS
#endif //TEMPLATE_PP_MMX && HAVE_6REGS
#if TEMPLATE_PP_MMX
#else
#endif
#if ARCH_X86 && TEMPLATE_PP_MMXEXT
#elif !ARCH_X86 && AV_GCC_VERSION_AT_LEAST(3,2)
#else
#endif
#ifdef TEMPLATE_PP_TIME_MODE
#else
#endif
#if TEMPLATE_PP_MMX
#endif
#if TEMPLATE_PP_MMX
#endif
#if TEMPLATE_PP_MMXEXT
#else
#endif
#if TEMPLATE_PP_MMX
#endif
#if TEMPLATE_PP_MMX
#endif
#if TEMPLATE_PP_MMX
#endif
#if TEMPLATE_PP_MMX
#else
#if TEMPLATE_PP_ALTIVEC
#else
#endif
#endif //TEMPLATE_PP_MMX
#if TEMPLATE_PP_MMX
#endif
#if   TEMPLATE_PP_3DNOW
#elif TEMPLATE_PP_MMX
#endif
#ifdef DEBUG_BRIGHTNESS
#endif
#undef RENAME
#undef TEMPLATE_PP_C
#undef TEMPLATE_PP_ALTIVEC
#undef TEMPLATE_PP_MMX
#undef TEMPLATE_PP_MMXEXT
#undef TEMPLATE_PP_3DNOW
#undef TEMPLATE_PP_SSE2

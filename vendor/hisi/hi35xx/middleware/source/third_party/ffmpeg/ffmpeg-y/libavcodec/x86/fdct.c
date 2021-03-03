#include "libavutil/common.h"
#include "libavutil/x86/asm.h"
#include "fdct.h"
#if HAVE_MMX_INLINE
#define BITS_FRW_ACC   3 //; 2 or 3 for accuracy
#define SHIFT_FRW_COL  BITS_FRW_ACC
#define SHIFT_FRW_ROW  (BITS_FRW_ACC + 17 - 3)
#define RND_FRW_ROW    (1 << (SHIFT_FRW_ROW-1))
#define X8(x) x,x,x,x,x,x,x,x
#define TABLE_SSE2 C4,  C4,  C1,  C3, -C6, -C2, -C1, -C5, \
#define C1 22725
#define C2 21407
#define C3 19266
#define C4 16384
#define C5 12873
#define C6 8867
#define C7 4520
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 31521
#define C2 29692
#define C3 26722
#define C4 22725
#define C5 17855
#define C6 12299
#define C7 6270
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 29692
#define C2 27969
#define C3 25172
#define C4 21407
#define C5 16819
#define C6 11585
#define C7 5906
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 26722
#define C2 25172
#define C3 22654
#define C4 19266
#define C5 15137
#define C6 10426
#define C7 5315
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 22725
#define C2 21407
#define C3 19266
#define C4 16384
#define C5 12873
#define C6 8867
#define C7 4520
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 26722
#define C2 25172
#define C3 22654
#define C4 19266
#define C5 15137
#define C6 10426
#define C7 5315
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 29692
#define C2 27969
#define C3 25172
#define C4 21407
#define C5 16819
#define C6 11585
#define C7 5906
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C1 31521
#define C2 29692
#define C3 26722
#define C4 22725
#define C5 17855
#define C6 12299
#define C7 6270
#define S(s) AV_TOSTRING(s) //AV_STRINGIFY is too long
#define FDCT_COL(cpu, mm, mov)\
#define FDCT_ROW_SSE2_H1(i,t)                    \
#define FDCT_ROW_SSE2_H2(i,t)                    \
#define FDCT_ROW_SSE2(i)                      \
#endif /* HAVE_MMX_INLINE */
#if HAVE_MMXEXT_INLINE
#endif /* HAVE_MMXEXT_INLINE */
#if HAVE_SSE2_INLINE
#endif /* HAVE_SSE2_INLINE */

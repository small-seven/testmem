#include "bzlib_private.h"
#define fswap(zz1, zz2) \
#define fvswap(zzp1, zzp2, zzn)       \
#define fmin(a,b) ((a) < (b)) ? (a) : (b)
#define fpush(lz,hz) { stackLo[sp] = lz; \
#define fpop(lz,hz) { sp--;              \
#define FALLBACK_QSORT_SMALL_THRESH 10
#define FALLBACK_QSORT_STACK_SIZE   100
#undef fmin
#undef fpush
#undef fpop
#undef fswap
#undef fvswap
#undef FALLBACK_QSORT_SMALL_THRESH
#undef FALLBACK_QSORT_STACK_SIZE
#define       SET_BH(zz)  bhtab[(zz) >> 5] |= (1 << ((zz) & 31))
#define     CLEAR_BH(zz)  bhtab[(zz) >> 5] &= ~(1 << ((zz) & 31))
#define     ISSET_BH(zz)  (bhtab[(zz) >> 5] & (1 << ((zz) & 31)))
#define      WORD_BH(zz)  bhtab[(zz) >> 5]
#define UNALIGNED_BH(zz)  ((zz) & 0x01f)
#undef       SET_BH
#undef     CLEAR_BH
#undef     ISSET_BH
#undef      WORD_BH
#undef UNALIGNED_BH
#define mswap(zz1, zz2) \
#define mvswap(zzp1, zzp2, zzn)       \
#define mmin(a,b) ((a) < (b)) ? (a) : (b)
#define mpush(lz,hz,dz) { stackLo[sp] = lz; \
#define mpop(lz,hz,dz) { sp--;             \
#define mnextsize(az) (nextHi[az]-nextLo[az])
#define mnextswap(az,bz)                                        \
#define MAIN_QSORT_SMALL_THRESH 20
#define MAIN_QSORT_DEPTH_THRESH (BZ_N_RADIX + BZ_N_QSORT)
#define MAIN_QSORT_STACK_SIZE 100
#undef mswap
#undef mvswap
#undef mpush
#undef mpop
#undef mmin
#undef mnextsize
#undef mnextswap
#undef MAIN_QSORT_SMALL_THRESH
#undef MAIN_QSORT_DEPTH_THRESH
#undef MAIN_QSORT_STACK_SIZE
#define BIGFREQ(b) (ftab[((b)+1) << 8] - ftab[(b) << 8])
#define SETMASK (1 << 21)
#define CLEARMASK (~(SETMASK))
#undef BIGFREQ
#undef SETMASK
#undef CLEARMASK

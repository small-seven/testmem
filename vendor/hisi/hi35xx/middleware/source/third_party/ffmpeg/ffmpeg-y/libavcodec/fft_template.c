#include <stdlib.h>
#include <string.h>
#include "libavutil/mathematics.h"
#include "libavutil/thread.h"
#include "fft.h"
#include "fft-internal.h"
#if FFT_FIXED_32
#include "fft_table.h"
#else /* FFT_FIXED_32 */
#if !CONFIG_HARDCODED_TABLES
typedef struct CosTabsInitOnce {
    void (*func)(void);
    AVOnce control;
} CosTabsInitOnce;
#define INIT_FF_COS_TABS_FUNC(index, size)          \
#endif
#endif /* FFT_FIXED_32 */
#if (!CONFIG_HARDCODED_TABLES) && (!FFT_FIXED_32)
#endif
#if CONFIG_MDCT
#endif
#if FFT_FIXED_32
#else /* FFT_FIXED_32 */
#if FFT_FLOAT
#else
#endif
#endif /* FFT_FIXED_32 */
#define PROCESS_FFT_PERM_SWAP_LSBS(num) do {\
#define PROCESS_FFT_PERM_DEFAULT(num) do {\
#define SPLIT_RADIX_PERMUTATION(num) do { \
#undef PROCESS_FFT_PERM_DEFAULT
#undef PROCESS_FFT_PERM_SWAP_LSBS
#undef SPLIT_RADIX_PERMUTATION
#if FFT_FIXED_32
#else /* FFT_FIXED_32 */
#define BUTTERFLIES(a0,a1,a2,a3) {\
#define BUTTERFLIES_BIG(a0,a1,a2,a3) {\
#define TRANSFORM(a0,a1,a2,a3,wre,wim) {\
#define TRANSFORM_ZERO(a0,a1,a2,a3) {\
#define PASS(name)\
#if !CONFIG_SMALL
#undef BUTTERFLIES
#define BUTTERFLIES BUTTERFLIES_BIG
#endif
#define DECL_FFT(n,n2,n4)\
#if !CONFIG_SMALL
#else
#endif
#if !CONFIG_SMALL
#define pass pass_big
#endif
#endif /* FFT_FIXED_32 */

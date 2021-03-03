#include <stdlib.h>
#include <string.h>
#include "libavutil/common.h"
#include "libavutil/libm.h"
#include "libavutil/mathematics.h"
#include "fft.h"
#include "fft-internal.h"
#if FFT_FLOAT
#   define RSCALE(x, y) ((x) + (y))
#else
#if FFT_FIXED_32
#   define RSCALE(x, y) ((int)((x) + (unsigned)(y) + 32) >> 6)
#else /* FFT_FIXED_32 */
#   define RSCALE(x, y) ((int)((x) + (unsigned)(y)) >> 1)
#endif /* FFT_FIXED_32 */
#endif
#if FFT_FIXED_32
#else
#endif

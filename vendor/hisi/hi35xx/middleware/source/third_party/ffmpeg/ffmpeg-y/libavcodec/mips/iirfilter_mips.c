#include "config.h"
#include "libavcodec/iirfilter.h"
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
typedef struct FFIIRFilterCoeffs {
    int   order;
    float gain;
    int   *cx;
    float *cy;
} FFIIRFilterCoeffs;
typedef struct FFIIRFilterState {
    float x[1];
} FFIIRFilterState;
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */

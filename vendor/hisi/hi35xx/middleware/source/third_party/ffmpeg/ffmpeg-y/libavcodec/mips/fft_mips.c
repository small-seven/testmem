#include "config.h"
#include "libavcodec/fft.h"
#include "libavcodec/fft_table.h"
#include "libavutil/mips/asmdefs.h"
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#if CONFIG_MDCT
#endif
#endif
#endif

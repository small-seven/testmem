#include "config.h"
#include "libavcodec/ac3dsp.h"
#include "libavcodec/ac3.h"
#include "libavutil/mips/asmdefs.h"
#if HAVE_INLINE_ASM
#if HAVE_MIPSDSP
#endif
#if HAVE_MIPSFPU
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_MIPSFPU */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if HAVE_MIPSDSP
#endif
#if HAVE_MIPSFPU
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif
#endif
#endif

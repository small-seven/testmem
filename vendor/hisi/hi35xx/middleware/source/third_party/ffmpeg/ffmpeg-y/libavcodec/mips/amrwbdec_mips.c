#include "libavutil/avutil.h"
#include "libavcodec/amrwbdata.h"
#include "amrwbdec_mips.h"
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */

#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavcodec/celp_filters.h"
#include "libavutil/mips/asmdefs.h"
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#endif
#endif

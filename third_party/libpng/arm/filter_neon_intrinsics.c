#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_ARM_NEON_IMPLEMENTATION == 1 /* intrinsics code from pngpriv.h */
#if defined(_MSC_VER) && defined(_M_ARM64)
#  include <arm64_neon.h>
#else
#  include <arm_neon.h>
#endif
#define png_ptr(type,pointer) png_aligncast(type *,pointer)
#define png_ptrc(type,pointer) png_aligncastconst(const type *,pointer)
#define png_ldr(type,pointer)\
#if PNG_ARM_NEON_OPT > 0
#endif /* PNG_ARM_NEON_OPT > 0 */
#endif /* PNG_ARM_NEON_IMPLEMENTATION == 1 (intrinsics) */
#endif /* READ */

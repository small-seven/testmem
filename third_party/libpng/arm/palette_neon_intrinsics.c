#include "../pngpriv.h"
#if PNG_ARM_NEON_IMPLEMENTATION == 1
#if defined(_MSC_VER) && defined(_M_ARM64)
#  include <arm64_neon.h>
#else
#  include <arm_neon.h>
#endif
#endif /* PNG_ARM_NEON_IMPLEMENTATION */

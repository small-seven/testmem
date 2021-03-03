#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_INTEL_SSE_IMPLEMENTATION > 0
#include <immintrin.h>
#if PNG_INTEL_SSE_IMPLEMENTATION >= 2
#else
#endif
#if PNG_INTEL_SSE_IMPLEMENTATION >= 3
#else
#endif
#endif /* PNG_INTEL_SSE_IMPLEMENTATION > 0 */
#endif /* READ */

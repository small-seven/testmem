#if !(defined(SECUREC_VXWORKS_PLATFORM))
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#ifndef _CRTIMP_ALTERNATIVE
#define _CRTIMP_ALTERNATIVE     /* Comment microsoft *_s function */
#endif
#ifndef __STDC_WANT_SECURE_LIB__
#define __STDC_WANT_SECURE_LIB__ 0
#endif
#endif
#include <wchar.h>
#endif
#undef SECUREC_ENABLE_WCHAR_FUNC
#define SECUREC_ENABLE_WCHAR_FUNC   0
#define SECUREC_FORMAT_OUTPUT_INPUT 1
#ifndef SECUREC_FOR_WCHAR
#define SECUREC_FOR_WCHAR
#endif
#if defined(SECUREC_WARP_OUTPUT) && SECUREC_WARP_OUTPUT
#undef SECUREC_WARP_OUTPUT
#define SECUREC_WARP_OUTPUT 0
#endif
#include "secureprintoutput.h"
#include "output.inl"

#if !(defined(SECUREC_VXWORKS_PLATFORM))
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#ifndef __STDC_WANT_SECURE_LIB__
#define __STDC_WANT_SECURE_LIB__ 0
#endif
#ifndef _CRTIMP_ALTERNATIVE
#define _CRTIMP_ALTERNATIVE     /* Comment microsoft *_s function */
#endif
#endif
#include <wchar.h>
#endif
#undef SECUREC_ENABLE_WCHAR_FUNC
#define SECUREC_ENABLE_WCHAR_FUNC       0
#define SECUREC_FORMAT_OUTPUT_INPUT     1
#ifndef SECUREC_FOR_WCHAR
#define SECUREC_FOR_WCHAR
#endif
#include "secinput.h"
#include "input.inl"

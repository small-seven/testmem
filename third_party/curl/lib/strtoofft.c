#include <errno.h>
#include "curl_setup.h"
#include "strtoofft.h"
#if (SIZEOF_CURL_OFF_T > SIZEOF_LONG)
#  ifdef HAVE_STRTOLL
#    define strtooff strtoll
#  else
#    if defined(_MSC_VER) && (_MSC_VER >= 1300) && (_INTEGRAL_MAX_BITS >= 64)
#      if defined(_SAL_VERSION)
#      else
#      endif
#      define strtooff _strtoi64
#    else
#      define PRIVATE_STRTOOFF 1
#    endif
#  endif
#else
#  define strtooff strtol
#endif
#ifdef PRIVATE_STRTOOFF
#if('9' - '0') != 9 || ('Z' - 'A') != 25 || ('z' - 'a') != 25
#define NO_RANGE_TEST
#endif
#ifndef NO_RANGE_TEST
#else
#endif
#endif  /* Only present if we need strtoll, but don't have it. */

#include "curl_setup.h"
#include "curl_endian.h"
#if (CURL_SIZEOF_CURL_OFF_T > 4)
#if defined(HAVE_LONGLONG)
#else
#endif
#endif /* CURL_SIZEOF_CURL_OFF_T > 4 */

#include "curl_setup.h"
#ifdef USE_WIN32_IDN
#include "curl_multibyte.h"
#include "curl_memory.h"
#include "warnless.h"
#include "memdebug.h"
#ifdef WANT_IDN_PROTOTYPES
#  if defined(_SAL_VERSION)
#  else
#  endif
#endif
#define IDN_MAX_LENGTH 255
#endif /* USE_WIN32_IDN */

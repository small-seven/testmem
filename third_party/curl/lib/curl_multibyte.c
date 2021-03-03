#include "curl_setup.h"
#include <curl/curl.h>
#if defined(USE_WIN32_IDN) || ((defined(USE_WINDOWS_SSPI) || \
#include "curl_multibyte.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* USE_WIN32_IDN || ((USE_WINDOWS_SSPI || USE_WIN32_LDAP) && UNICODE) */

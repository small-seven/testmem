#include "curl_setup.h"
#include <curl/curl.h>
#include "vauth.h"
#include "curl_multibyte.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if !defined(USE_WINDOWS_SSPI)
#else
#endif /* USE_WINDOWS_SSPI */
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
#endif

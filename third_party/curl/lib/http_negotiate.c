#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP) && defined(USE_SPNEGO)
#include "urldata.h"
#include "sendf.h"
#include "http_negotiate.h"
#include "vauth/vauth.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(USE_WINDOWS_SSPI) && defined(SECPKG_ATTR_ENDPOINT_BINDINGS)
#endif
#endif /* !CURL_DISABLE_HTTP && USE_SPNEGO */

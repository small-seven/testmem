#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_CRYPTO_AUTH)
#include "urldata.h"
#include "strcase.h"
#include "vauth/vauth.h"
#include "http_digest.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(USE_WINDOWS_SSPI)
#else
#endif
#endif

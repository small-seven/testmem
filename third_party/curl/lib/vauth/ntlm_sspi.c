#include "curl_setup.h"
#if defined(USE_WINDOWS_SSPI) && defined(USE_NTLM)
#include <curl/curl.h>
#include "vauth/vauth.h"
#include "urldata.h"
#include "curl_base64.h"
#include "curl_ntlm_core.h"
#include "warnless.h"
#include "curl_multibyte.h"
#include "sendf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef SECPKG_ATTR_ENDPOINT_BINDINGS
#endif
#endif /* USE_WINDOWS_SSPI && USE_NTLM */

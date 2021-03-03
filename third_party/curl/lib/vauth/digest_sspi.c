#include "curl_setup.h"
#if defined(USE_WINDOWS_SSPI) && !defined(CURL_DISABLE_CRYPTO_AUTH)
#include <curl/curl.h>
#include "vauth/vauth.h"
#include "vauth/digest.h"
#include "urldata.h"
#include "curl_base64.h"
#include "warnless.h"
#include "curl_multibyte.h"
#include "sendf.h"
#include "strdup.h"
#include "strcase.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* USE_WINDOWS_SSPI && !CURL_DISABLE_CRYPTO_AUTH */

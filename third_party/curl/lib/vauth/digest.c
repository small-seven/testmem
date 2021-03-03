#include "curl_setup.h"
#if !defined(CURL_DISABLE_CRYPTO_AUTH)
#include <curl/curl.h>
#include "vauth/vauth.h"
#include "vauth/digest.h"
#include "urldata.h"
#include "curl_base64.h"
#include "curl_hmac.h"
#include "curl_md5.h"
#include "curl_sha256.h"
#include "vtls/vtls.h"
#include "warnless.h"
#include "strtok.h"
#include "strcase.h"
#include "non-ascii.h" /* included for Curl_convert_... prototypes */
#include "curl_printf.h"
#include "rand.h"
#include "curl_memory.h"
#include "memdebug.h"
#if !defined(USE_WINDOWS_SSPI)
#define DIGEST_QOP_VALUE_AUTH             (1 << 0)
#define DIGEST_QOP_VALUE_AUTH_INT         (1 << 1)
#define DIGEST_QOP_VALUE_AUTH_CONF        (1 << 2)
#define DIGEST_QOP_VALUE_STRING_AUTH      "auth"
#define DIGEST_QOP_VALUE_STRING_AUTH_INT  "auth-int"
#define DIGEST_QOP_VALUE_STRING_AUTH_CONF "auth-conf"
#define CURL_OUTPUT_DIGEST_CONV(a, b) \
#endif /* !USE_WINDOWS_SSPI */
#if !defined(USE_WINDOWS_SSPI)
#endif  /* !USE_WINDOWS_SSPI */
#endif  /* CURL_DISABLE_CRYPTO_AUTH */

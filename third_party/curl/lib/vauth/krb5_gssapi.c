#include "curl_setup.h"
#if defined(HAVE_GSSAPI) && defined(USE_KERBEROS5)
#include <curl/curl.h>
#include "vauth/vauth.h"
#include "curl_sasl.h"
#include "urldata.h"
#include "curl_base64.h"
#include "curl_gssapi.h"
#include "sendf.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* HAVE_GSSAPI && USE_KERBEROS5 */

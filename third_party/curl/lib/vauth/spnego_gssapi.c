#include "curl_setup.h"
#if defined(HAVE_GSSAPI) && defined(USE_SPNEGO)
#include <curl/curl.h>
#include "vauth/vauth.h"
#include "urldata.h"
#include "curl_base64.h"
#include "curl_gssapi.h"
#include "warnless.h"
#include "curl_multibyte.h"
#include "sendf.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* HAVE_GSSAPI && USE_SPNEGO */

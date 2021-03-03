#include "curl_setup.h"
#if !defined(CURL_DISABLE_IMAP) || !defined(CURL_DISABLE_SMTP) || \
#include <curl/curl.h>
#include "urldata.h"
#include "vauth/vauth.h"
#include "curl_base64.h"
#include "warnless.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* disabled, no users */

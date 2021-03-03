#include "curl_setup.h"
#if !defined(CURL_DISABLE_IMAP) || !defined(CURL_DISABLE_SMTP) ||       \
#include <curl/curl.h>
#include "urldata.h"
#include "vauth/vauth.h"
#include "curl_base64.h"
#include "curl_md5.h"
#include "warnless.h"
#include "strtok.h"
#include "sendf.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* if no users */

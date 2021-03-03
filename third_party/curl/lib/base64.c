#include "curl_setup.h"
#if !defined(CURL_DISABLE_HTTP_AUTH) || defined(USE_SSH) || \
#include "urldata.h" /* for the Curl_easy definition */
#include "warnless.h"
#include "curl_base64.h"
#include "non-ascii.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if SIZEOF_SIZE_T == 4
#endif
#endif /* no users so disabled */

#include "curl_setup.h"
#ifndef CURL_DISABLE_HTTP
#include "urldata.h" /* it includes http_chunks.h */
#include "sendf.h"   /* for the client write stuff */
#include "content_encoding.h"
#include "http.h"
#include "non-ascii.h" /* for Curl_convert_to_network prototype */
#include "strtoofft.h"
#include "warnless.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef CURL_DOES_CONVERSIONS
#else
#define Curl_isxdigit_ascii(x) Curl_isxdigit(x)
#endif
#endif /* CURL_DISABLE_HTTP */

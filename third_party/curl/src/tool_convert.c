#include "tool_setup.h"
#ifdef CURL_DOES_CONVERSIONS
#ifdef HAVE_ICONV
#  include <iconv.h>
#endif
#include "tool_convert.h"
#include "memdebug.h" /* keep this as LAST include */
#ifdef HAVE_ICONV
#ifndef CURL_ICONV_CODESET_OF_NETWORK
#  define CURL_ICONV_CODESET_OF_NETWORK "ISO8859-1"
#endif
#endif /* HAVE_ICONV */
#endif /* CURL_DOES_CONVERSIONS */

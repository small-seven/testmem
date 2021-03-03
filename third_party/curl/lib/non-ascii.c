#include "curl_setup.h"
#ifdef CURL_DOES_CONVERSIONS
#include <curl/curl.h>
#include "non-ascii.h"
#include "formdata.h"
#include "sendf.h"
#include "urldata.h"
#include "multiif.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef HAVE_ICONV
#include <iconv.h>
#ifndef CURL_ICONV_CODESET_OF_NETWORK
#define CURL_ICONV_CODESET_OF_NETWORK "ISO8859-1"
#endif
#ifndef CURL_ICONV_CODESET_FOR_UTF8
#define CURL_ICONV_CODESET_FOR_UTF8   "UTF-8"
#endif
#define ICONV_ERROR  (size_t)-1
#endif /* HAVE_ICONV */
#ifdef HAVE_ICONV
#else
#endif /* HAVE_ICONV */
#ifdef HAVE_ICONV
#else
#endif /* HAVE_ICONV */
#ifdef HAVE_ICONV
#else
#endif /* HAVE_ICONV */
#if defined(CURL_DOES_CONVERSIONS) && defined(HAVE_ICONV)
#else
#endif /* CURL_DOES_CONVERSIONS && HAVE_ICONV */
#ifdef HAVE_ICONV
#else
#endif /* HAVE_ICONV */
#endif /* CURL_DOES_CONVERSIONS */

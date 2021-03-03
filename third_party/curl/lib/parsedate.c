#include "curl_setup.h"
#include <limits.h>
#include <curl/curl.h>
#include "strcase.h"
#include "warnless.h"
#include "parsedate.h"
#define PARSEDATE_OK     0
#define PARSEDATE_FAIL   -1
#define PARSEDATE_LATER  1
#define PARSEDATE_SOONER 2
#if !defined(CURL_DISABLE_PARSEDATE) || !defined(CURL_DISABLE_FTP) || \
#endif
#ifndef CURL_DISABLE_PARSEDATE
#define tDAYZONE -60       /* offset for daylight savings time */
#if LONG_MAX != INT_MAX
#endif
#ifdef HAVE_TIME_T_UNSIGNED
#endif
#if (SIZEOF_TIME_T < 5)
#ifdef HAVE_TIME_T_UNSIGNED
#else
#endif
#else
#endif
#else
#endif
#ifdef HAVE_GMTIME_R
#else
#endif

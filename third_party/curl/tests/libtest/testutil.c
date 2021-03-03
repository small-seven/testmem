#include "curl_setup.h"
#include <curl/curl.h>
#include "testutil.h"
#include "memdebug.h"
#if defined(WIN32) && !defined(MSDOS)
#elif defined(HAVE_CLOCK_GETTIME_MONOTONIC)
#ifdef HAVE_GETTIMEOFDAY
#else
#endif
#elif defined(HAVE_GETTIMEOFDAY)
#else
#endif

#include "tool_filetime.h"
#ifdef HAVE_UTIME_H
#  include <utime.h>
#elif defined(HAVE_SYS_UTIME_H)
#  include <sys/utime.h>
#endif
#if defined(WIN32) && (SIZEOF_CURL_OFF_T >= 8)
#else
#endif
#if defined(HAVE_UTIME) || defined(HAVE_UTIMES) || \
#if defined(WIN32) && (SIZEOF_CURL_OFF_T >= 8)
#elif defined(HAVE_UTIMES)
#elif defined(HAVE_UTIME)
#endif
#endif /* defined(HAVE_UTIME) || defined(HAVE_UTIMES) || \

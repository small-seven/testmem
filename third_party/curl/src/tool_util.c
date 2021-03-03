#include "tool_setup.h"
#include "tool_util.h"
#include "memdebug.h" /* keep this as LAST include */
#if defined(WIN32) && !defined(MSDOS)
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:28159)
#endif
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
#elif defined(HAVE_CLOCK_GETTIME_MONOTONIC)
#ifdef HAVE_GETTIMEOFDAY
#else
#endif
#elif defined(HAVE_GETTIMEOFDAY)
#else
#endif

#include "timeval.h"
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
#endif
#if defined(__APPLE__) && (HAVE_BUILTIN_AVAILABLE == 1)
#endif
#if defined(__APPLE__) && (HAVE_BUILTIN_AVAILABLE == 1)
#endif
#ifdef HAVE_GETTIMEOFDAY
#else
#endif
#elif defined(HAVE_MACH_ABSOLUTE_TIME)
#include <stdint.h>
#include <mach/mach_time.h>
#elif defined(HAVE_GETTIMEOFDAY)
#else
#endif

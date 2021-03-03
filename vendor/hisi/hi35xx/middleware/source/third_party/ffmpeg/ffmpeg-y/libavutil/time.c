#include "config.h"
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#if HAVE_GETTIMEOFDAY
#include <sys/time.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_WINDOWS_H
#include <windows.h>
#endif
#include "time.h"
#include "error.h"
#if HAVE_GETTIMEOFDAY
#elif HAVE_GETSYSTEMTIMEASFILETIME
#else
#endif
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#ifdef __APPLE__
#endif
#endif
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#ifdef __APPLE__
#endif
#else
#endif
#if HAVE_NANOSLEEP
#elif HAVE_USLEEP
#elif HAVE_SLEEP
#else
#endif

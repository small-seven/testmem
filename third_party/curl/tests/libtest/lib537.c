#include "test.h"
#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#include <limits.h>
#include "warnless.h"
#include "memdebug.h"
#if !defined(HAVE_POLL_FINE)    && \
#error "this test requires FD_SETSIZE"
#endif
#define SAFETY_MARGIN (11)
#if defined(WIN32) || defined(_WIN32) || defined(MSDOS)
#define DEV_NULL "NUL"
#else
#define DEV_NULL "/dev/null"
#endif
#if defined(HAVE_GETRLIMIT) && defined(HAVE_SETRLIMIT)
#ifdef HAVE_LONGLONG
#endif
#ifdef RLIM_INFINITY
#endif
#ifdef RLIM_INFINITY
#endif
#ifdef OPEN_MAX
#endif
#ifdef RLIM_INFINITY
#endif
#ifdef RLIM_INFINITY
#endif
#ifdef RLIM_INFINITY
#else
#endif
#if !defined(HAVE_POLL_FINE)    && \
#endif /* using a FD_SETSIZE bound select() */
#else /* defined(HAVE_GETRLIMIT) && defined(HAVE_SETRLIMIT) */
#endif /* defined(HAVE_GETRLIMIT) && defined(HAVE_SETRLIMIT) */

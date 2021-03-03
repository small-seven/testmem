#include "curl_setup.h"
#if defined(USE_MBEDTLS) &&                                     \
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#  include <pthread.h>
#  define MBEDTLS_MUTEX_T pthread_mutex_t
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#  include <process.h>
#  define MBEDTLS_MUTEX_T HANDLE
#endif
#include "mbedtls_threadlock.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define NUMT                    2
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
#if defined(USE_THREADS_POSIX) && defined(HAVE_PTHREAD_H)
#elif defined(USE_THREADS_WIN32) && defined(HAVE_PROCESS_H)
#endif /* USE_THREADS_POSIX && HAVE_PTHREAD_H */
#endif /* USE_MBEDTLS */

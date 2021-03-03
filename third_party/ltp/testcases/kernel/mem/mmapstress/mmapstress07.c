#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#define ERROR(M)	(void)fprintf(stderr, "%s: errno = %d: " M "\n", \
#define CLEANERROR(M)	(void)close(rofd); \
#define CATCH_SIG(SIG) \
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */

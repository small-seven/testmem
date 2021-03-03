#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#if defined(__i386__) || defined(__x86_64__)
#define NPTEPG		(1024)
#define GRAN_NUMBER	(1<<8)
#define ERROR(M) (void)fprintf(stderr, "%s: errno = %d: " M "\n", argv[0], \
#else /* defined(__i386__) || defined(__x86_64__) */
#endif

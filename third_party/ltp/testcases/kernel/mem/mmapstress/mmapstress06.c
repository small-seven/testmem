#define _KMEMUSER
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#define ANON_GRAN_PAGES_MAX	(32U)
#define NMFPTEPG		(1024)
#define ERROR(M)	(void)fprintf(stderr, "%s: errno = %d; " M "\n", \

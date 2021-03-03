#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#define	ERROR(M)	(void)fprintf(stderr, "%s: errno = %d; " M "\n", \
#define CLEANERROR(M)	(void)unlink(tmpname); ERROR(M)
#define CATCH_SIG(SIG) \
#include "test.h"
#define FAILED 0
#define PASSED 1

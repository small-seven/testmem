#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include "test.h"
#ifndef MMU_NARROWPTEPG
#define MMU_NARROWPTEPG	1024
#endif
#define FAILED 0
#define PASSED 1
#define ERROR(M)	(void)fprintf(stderr, "%s:  errno = %d; " M "\n", \
#define CLEAN	(void)close(fd); \
#define CERROR(M)	CLEAN; ERROR(M)
#define CATCH_SIG(SIG) \

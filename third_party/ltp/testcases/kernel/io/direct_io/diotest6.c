#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/file.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/uio.h>
#include <errno.h>
#include "diotest_routines.h"
#include "test.h"
#ifdef O_DIRECT
#define	BUFSIZE	4096
#define TRUE 1
#define LEN 30
#define	READ_DIRECT 1
#define	WRITE_DIRECT 2
#define	RDWR_DIRECT 3
#else /* O_DIRECT */
#endif /* O_DIRECT */

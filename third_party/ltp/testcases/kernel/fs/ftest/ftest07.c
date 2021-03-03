#define _XOPEN_SOURCE 500
#define _LARGEFILE64_SOURCE 1
#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include "test.h"
#include "safe_macros.h"
#include "libftest.h"
#define PASSED 1
#define FAILED 0
#define MAXCHILD	25
#define K_1		1024
#define K_2		2048
#define K_4		4096
#define	MAXIOVCNT	16
#define	NMISC	4
#define	NEXTMISC	((rand() % misc_intvl) + 5)

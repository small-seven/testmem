#define _GNU_SOURCE 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
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
#define	NMISC	4
#define	CHUNK(i)	((i) * csize)
#define	NEXTMISC	((rand() % misc_intvl) + 5)

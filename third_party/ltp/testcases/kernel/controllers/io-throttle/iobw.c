#define _GNU_SOURCE
#define __USE_GNU
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#ifndef PAGE_SIZE
#define PAGE_SIZE sysconf(_SC_PAGE_SIZE)
#endif
#define align(x,a)		__align_mask(x,(typeof(x))(a)-1)
#define __align_mask(x,mask)	(((x)+(mask))&~(mask))
#define kb(x)			((x) >> 10)
typedef enum {
	OP_WRITE,
	OP_READ,
	NUM_IOPS,
} iops_t;

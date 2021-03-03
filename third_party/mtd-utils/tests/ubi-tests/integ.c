#define _LARGEFILE64_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include "libubi.h"
#define PROGRAM_NAME "integ"
#include "common.h"
#include "helpers.h"
#define MAX_UBI_DEVICES 64
static void *allocate(size_t n)
{
	void *p = malloc(n);
	if (!p)
		error_exit("Memory allocation failure");
	memset(p, 0, n);
	return p;
}

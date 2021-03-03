#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "lapi/fallocate.h"
#include "lapi/fcntl.h"
#include "lapi/memfd.h"
#include "lapi/syscalls.h"
#include "memfd_create_common.h"
int check_fallocate(const char *filename, const int lineno, int fd,
			int mode, off_t offset, off_t len)
{
	int r;

	r = fallocate(fd, mode, offset, len);
	if (r < 0) {
		tst_brk_(filename, lineno, TFAIL | TERRNO,
			"fallocate(%d, %d, %ld, %ld) failed", fd, mode,
			offset, len);
	}

	tst_res_(filename, lineno, TPASS,
		"fallocate(%d, %d, %ld, %ld) succeeded", fd, mode,
		offset, len);

	return r;
}

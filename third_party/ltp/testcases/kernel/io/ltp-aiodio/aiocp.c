#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <mntent.h>
#include <sys/select.h>
#include <sys/mount.h>
#include "config.h"
#include "tst_res_flags.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define AIO_BLKSIZE	(64*1024)
#define AIO_MAXIO	32
#else
#endif

#define PROGRAM_NAME "libubi"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libubi.h>
#include "libubi_int.h"
#include "common.h"
#ifndef MTD_CHAR_MAJOR
#define MTD_CHAR_MAJOR 90
#endif
int ubi_vol_block_remove(int fd)
{
	return ioctl(fd, UBI_IOCVOLRMBLK, NULL);
}

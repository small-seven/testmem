#define PROGRAM_NAME "mtd_debug"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mtd/mtd-user.h>
#include "common.h"
#define BUF_SIZE	(64 * 1024 * sizeof(u_int8_t))

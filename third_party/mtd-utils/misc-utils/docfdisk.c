#define PROGRAM_NAME "docfdisk"
#define _XOPEN_SOURCE 500 /* for pread/pwrite */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <errno.h>
#include <string.h>
#include <asm/types.h>
#include <mtd/mtd-user.h>
#include <mtd/inftl-user.h>
#include <mtd_swab.h>
#define MAXSCAN 10

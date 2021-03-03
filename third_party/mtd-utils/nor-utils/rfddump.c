#define PROGRAM_NAME "rfddump"
#define _XOPEN_SOURCE 500 /* For pread */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <mtd/mtd-user.h>
#include <linux/types.h>
#include <mtd_swab.h>
#include "common.h"
#define RFD_MAGIC		0x9193
#define HEADER_MAP_OFFSET       3
#define SECTOR_DELETED          0x0000
#define SECTOR_ZERO             0xfffe
#define SECTOR_FREE             0xffff
#define SECTOR_SIZE             512
#define SECTORS_PER_TRACK	63

#define PROGRAM_NAME "nftldump"
#define _XOPEN_SOURCE 500 /* For pread */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <asm/types.h>
#include <mtd/mtd-user.h>
#include <mtd/nftl-user.h>
#include <mtd_swab.h>
#include "common.h"
#define SWAP16(x) do { x = le16_to_cpu(x); } while(0)
#define SWAP32(x) do { x = le32_to_cpu(x); } while(0)
#define ERASESIZE 0x2000
#define NUMVUNITS ((40*1024*1024) / ERASESIZE)

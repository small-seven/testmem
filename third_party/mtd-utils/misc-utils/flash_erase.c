#define PROGRAM_NAME "flash_erase"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <common.h>
#include <crc32.h>
#include <libmtd.h>
#include <mtd/mtd-user.h>
#include <mtd/jffs2-user.h>

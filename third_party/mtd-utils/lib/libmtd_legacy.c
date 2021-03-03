#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include <libmtd.h>
#include "libmtd_int.h"
#include "common.h"
#define MTD_PROC_FILE "/proc/mtd"
#define MTD_DEV_PATT  "/dev/mtd%d"
#define MTD_DEV_MAJOR 90
#define PROC_MTD_FIRST     "dev:    size   erasesize  name\n"
#define PROC_MTD_FIRST_LEN (sizeof(PROC_MTD_FIRST) - 1)
#define PROC_MTD_MAX_LEN   4096
#define PROC_MTD_PATT      "mtd%d: %llx %x"

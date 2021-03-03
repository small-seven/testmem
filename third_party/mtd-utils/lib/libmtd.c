#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <inttypes.h>
#include <mtd/mtd-user.h>
#include <libmtd.h>
#include "libmtd_int.h"
#include "common.h"
#define mtd_xlock(mtd, fd, eb, req) mtd_xlock(mtd, fd, eb, req, #req)

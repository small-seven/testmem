#define PROGRAM_NAME "ftl_check"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <getopt.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <mtd/mtd-user.h>
#include <mtd/ftl-user.h>
#include <mtd_swab.h>
#include "common.h"

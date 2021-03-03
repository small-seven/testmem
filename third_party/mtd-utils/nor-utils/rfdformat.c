#define PROGRAM_NAME "rfdformat"
#define _XOPEN_SOURCE 500 /* For pread/pwrite */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <mtd/mtd-user.h>
#include <linux/types.h>
#include "common.h"

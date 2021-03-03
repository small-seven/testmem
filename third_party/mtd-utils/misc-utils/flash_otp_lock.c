#define PROGRAM_NAME "flash_otp_lock"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include "common.h"

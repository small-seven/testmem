#define PROGRAM_NAME "flash_otp_write"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <common.h>
#include <mtd/mtd-user.h>

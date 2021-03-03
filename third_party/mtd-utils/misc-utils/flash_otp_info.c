#define PROGRAM_NAME "flash_otp_info"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>

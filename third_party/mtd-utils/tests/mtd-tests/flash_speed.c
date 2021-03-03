#define DESTRUCTIVE 0x01
#define PROGRAM_NAME "flash_speed"
#include <mtd/mtd-user.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <libmtd.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "common.h"
#define TIME_OP_PER_PEB( op )\

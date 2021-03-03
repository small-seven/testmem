#define PROGRAM_NAME "nanddump"
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <asm/types.h>
#include <mtd/mtd-user.h>
#include "common.h"
#include <libmtd.h>
#define PRETTY_ROW_SIZE 16
#define PRETTY_BUF_LEN 80

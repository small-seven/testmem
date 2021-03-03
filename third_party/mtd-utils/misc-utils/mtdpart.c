#define PROGRAM_NAME "mtdpart"
#include <fcntl.h>
#include <getopt.h>
#include <limits.h>
#include <linux/blkpg.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "common.h"
typedef enum {
	COMMAND_ADD,
	COMMAND_DEL
} command_type;

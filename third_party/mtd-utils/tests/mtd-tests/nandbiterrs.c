#define PROGRAM_NAME "nandbiterrs"
#include <mtd/mtd-user.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <libmtd.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include "common.h"
#define MAXBITS 512
#define KEEP_CONTENTS 0x01
#define MODE_INCREMENTAL 0x02
#define MODE_OVERWRITE 0x04
#define PAGE_ERASED 0x08

#ifndef PROGRAM_NAME
#define PROGRAM_NAME		"flash_unlock"
#define DEFAULT_REQUEST		REQUEST_UNLOCK
#else
#define DEFAULT_REQUEST		REQUEST_LOCK
#endif
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <string.h>
#include "common.h"
#include <mtd/mtd-user.h>

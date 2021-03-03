#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/ioctl.h"
#define MASTERCLONE "/dev/ptmx"
#define STRING "Linux Test Project\n"
#define TESTSIZE 1024
#define PTY_MODE 020622
#define NUMPROCS 15
#ifndef __BIONIC__
#endif

#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/poll.h>
#include <sys/types.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/ioctl.h"
#define MASTERCLONE "/dev/ptmx"
#define BUFSZ 4096
#define NUMOPENS 6

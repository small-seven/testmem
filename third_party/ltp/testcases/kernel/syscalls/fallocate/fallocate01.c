#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <endian.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/utsname.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fallocate.h"
#include "lapi/fcntl.h"
#define BLOCKS_WRITTEN 12

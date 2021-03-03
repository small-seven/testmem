#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <endian.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>		//Can be done with out
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/utsname.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fallocate.h"
#define BLOCKS_WRITTEN 12
#define HOLE_SIZE_IN_BLOCKS 12
#define DEFAULT_MODE 0
#define TRUE 0

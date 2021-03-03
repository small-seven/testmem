#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#define MNTPOINT	"mntpoint"
#define FS_BLOCKSIZE	1024
#define SUB_LOOPCOUNT	10

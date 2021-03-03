#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <dirent.h>
#include <ctype.h>
#include <limits.h>
#include <mntent.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/vfs.h>
#include <sys/mount.h>
#include <sys/statvfs.h>
#include <linux/fs.h>
#include <linux/jffs2.h>
#include "tests.h"
#define WRITE_BUFFER_SIZE 32768
#define PID_BUF_SIZE 64

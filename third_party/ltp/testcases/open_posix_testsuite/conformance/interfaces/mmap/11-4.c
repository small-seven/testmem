#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#ifdef	__linux__
#include <sys/vfs.h>
#endif
#include "posixtest.h"
#define TYPE_TMPFS_MAGIC	0x01021994
#ifdef	__linux__
#endif

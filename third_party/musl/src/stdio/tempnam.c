#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "syscall.h"
#include "kstat.h"
#define MAXTRIES 100
#ifdef SYS_lstat
#else
#endif

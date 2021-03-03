#include "config.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <fnmatch.h>
#ifdef HAVE_LIBSELINUX_DEVEL
#include <selinux/selinux.h>
#endif
#include "test.h"
#define MAX_BUFF_SIZE 65536
#define MAX_FUNC_NAME 256
#ifdef HAVE_LIBSELINUX_DEVEL
#else
#endif
#ifdef HAVE_LIBSELINUX_DEVEL
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
